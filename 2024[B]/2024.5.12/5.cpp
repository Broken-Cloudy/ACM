#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100009],i,j,ans,s[1000009];
int anss,zhi[1000008],maxzhi,kk,vis[1000008],abc;//anss质数的数量 
int K1[101][100009],K2[80001][1009],cnt,bh[100008],bhk[100008],flag[1000008];
bool ff;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	flag[1]=1;
	for(i=2;i<=1000000;i++){
		if(flag[i]==0){
			zhi[++anss]=i;//记录下来 
		}
		for(j=1;j<=anss&&i*zhi[j]<=1000000;j++){
			flag[zhi[j]*i]=1;//一下子筛到底 
			//当然，i肯定比ans[j]大，因为ans[j]是在i之前得出的
			if(i%zhi[j]==0)break;
		}
	}
	for(i=1;i<=1000000;i++){
		if(flag[i]==0)kk++,flag[i]=kk;
		else flag[i]=0;
	}
	for(i=1;i<=n;i++){
		ff=0;maxzhi=0;
		for(j=1;j<=anss&&zhi[j]*zhi[j]<=a[i];j++){
			if(a[i]%zhi[j]==0){
				ff=1;
				maxzhi=max(maxzhi,j);
			}
		}
		if(flag[a[i]]<=100)abc=1;
		else abc=2;
		if(ff==0){
			if(abc==1){
				K1[flag[a[i]]][++K1[flag[a[i]]][0]]=i;
				bh[i]=flag[a[i]];
				bhk[i]=K1[flag[a[i]]][0];
			}
			else{
				K2[flag[a[i]]][++K2[flag[a[i]]][0]]=i;
				bh[i]=flag[a[i]];
				bhk[i]=K2[flag[a[i]]][0];
			}
		}
		else{
			if(abc==1){
				K1[maxzhi][++K1[maxzhi][0]]=i;
				bh[i]=maxzhi;
			}
			else{
				K2[maxzhi][++K2[maxzhi][0]]=i;
				bh[i]=maxzhi;
			}
			
		}
	}
	for(i=1;i<=n;i++){
		if(a[i]==1){
			ans+=(i-1);
			continue;
		}
		else ans+=s[a[i]];
		if(flag[a[i]]<=100)abc=1;
		else abc=2;
		if(abc==1){
			for(j=bhk[i]+1;j<=K1[bh[i]][0];j++){
				int kt=a[i]*a[i];
				if(kt%a[K1[bh[i]][j]]==0&&vis[a[K1[bh[i]][j]]]==0){
					s[a[K1[bh[i]][j]]]++;
					vis[a[K1[bh[i]][j]]]=1;
				}
			}
			for(j=bhk[i]+1;j<=K1[bh[i]][0];j++){
				if((a[i]*a[i])%a[K1[bh[i]][j]]==0){
					vis[a[K1[bh[i]][j]]]=0;
				}
			}
		}
		else{
			for(j=bhk[i]+1;j<=K2[bh[i]][0];j++){
				int kt=a[i]*a[i];
				if(kt%a[K2[bh[i]][j]]==0&&vis[a[K2[bh[i]][j]]]==0){
					s[a[K2[bh[i]][j]]]++;
					vis[a[K2[bh[i]][j]]]=1;
				}
			}
			for(j=bhk[i]+1;j<=K2[bh[i]][0];j++){
				if((a[i]*a[i])%a[K2[bh[i]][j]]==0){
					vis[a[K2[bh[i]][j]]]=0;
				}
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
