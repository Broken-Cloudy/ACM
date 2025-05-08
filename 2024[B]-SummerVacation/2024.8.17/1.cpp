#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1000000009LL;
int T,n,i,k,ans,a,b,j;
int val[1009][209],w[1009][209],cnt[1009];
int f[309];
void work(int a,int b,int i){
	int C=0,V=0,W=0;
	while(a>0&&b>0){
		if(a==1&&b==1){
			a=0;b=0;C++;
			V+=2;W+=1;
			val[i][C]=V;
			w[i][C]=W;
		}
		else{
			C++;V+=1;W+=min(a,b);
			if(a==min(a,b))b--;
			else a--;
			val[i][C]=V;
			w[i][C]=W;
		}
	}
	cnt[i]=C;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);ans=inf;
		for(i=1;i<=n;i++){
			scanf("%lld%lld",&a,&b);
			work(a,b,i);//预处理,分组背包 
		}
		for(i=k+100;i>=0;i--)f[i]=inf;f[0]=0;
		for(int group=1;group<=n;group++){
			for(i=k+100;i>=0;i--){
				for(j=1;j<=cnt[group];j++){
					if(val[group][j]<=i){
						f[i]=min(f[i],f[i-val[group][j]]+w[group][j]);
					}
				}
			}
		}
		for(i=k;i<=k+100;i++){
			ans=min(ans,f[i]);
		}
		if(ans==inf)printf("-1\n");
		else printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
