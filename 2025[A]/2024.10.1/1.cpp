#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,k,a[400009],n,b[24],cnt,vis[24],sum[24],poi[24][400009],ANS=0,ANSS=1e18;
int zuo[400009][24],you[400009][24],ans[400009];//zuo<=当前位置  you>当前位置 
void work(int bi){
	int i,j,nowans=0,minans=0,bh=bi;
	//myself
	for(i=1;i<=sum[b[bi]];i++)ans[i]=0;
	for(i=1;i<=sum[b[bi]];i++){//O(400000*20)
		for(j=1;j<=cnt;j++){
			if(j<bi){
				ans[i]+=you[poi[b[bi]][i]][b[j]];
			}
			if(j>bi){
				ans[i]+=zuo[poi[b[bi]][i]][b[j]];
			}
		}
		minans+=ans[i];
	}
	for(i=bi-1;i>=1;i--){//O(400000*20)
		nowans=0;
		for(j=1;j<=sum[b[bi]];j++){
			ans[j]-=you[poi[b[bi]][j]][b[i]];
			ans[j]+=zuo[poi[b[bi]][j]][b[i]];
			nowans+=ans[j];
		}
		if(nowans<minans){
			bh=i;minans=nowans;
		}
	}
	for(i=bi+1;i<=cnt;i++){//O(400000*20)
		nowans=0;
		for(j=1;j<=sum[b[bi]];j++){
			ans[j]+=you[poi[b[bi]][j]][b[i]];
			ans[j]-=zuo[poi[b[bi]][j]][b[i]];
			nowans+=ans[j];
		}
		if(nowans<minans){
			bh=i;minans=nowans;
		}
	}
	if(bh!=bi){
		if(bh<bi)for(i=bi;i>=bh+1;i--)swap(b[i],b[i-1]);
		else for(i=bh;i>=bi+1;i--)swap(b[i],b[i-1]);
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(!vis[a[i]]){vis[a[i]]=1;b[++cnt]=a[i];}
		sum[a[i]]++;poi[a[i]][sum[a[i]]]=i;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=20;j++)zuo[i][j]=zuo[i-1][j];
		zuo[i][a[i]]++;
		for(j=1;j<=20;j++)you[i][j]=sum[j]-zuo[i][j];
	}
	for(i=1;i<=15;i++)for(int o=2;o<=cnt;o++){//20
		work(o);
	}
	ANS=0;
		for(i=1;i<=cnt;i++){//20
			for(j=1;j<=sum[b[i]];j++){//400000
				for(k=i+1;k<=cnt;k++){//20
					ANS+=zuo[poi[b[i]][j]][b[k]];
				}
			}
		}
		ANSS=min(ANS,ANSS);
	cout<<min(ANS,ANSS)<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
