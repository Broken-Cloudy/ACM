#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18+9;
int T,i,j,n,m,k,a[209][209],dp[209][209],x,y,t;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%lld",&a[i][j]);
		for(i=0;i<=n;i++)for(j=0;j<=m;j++)dp[i][j]=INF;
		dp[0][1]=0;
		for(i=1;i<=n;i++){
			for(t=0;t<m;t++){//±ä»»´ÎÊý 
				vector<int>tmp(m+1,1e18);
				for(j=1;j<=m;j++){
					tmp[j]=dp[i-1][j]+a[i][(j+t-1)%m+1]+k*t;
				}
				for(j=1;j<=m;j++){
					tmp[j]=min(tmp[j],tmp[(j-1+m-1)%m+1]+a[i][(j+t-1)%m+1]);
				}
				for(j=1;j<=m;j++){
					dp[i][j]=min(dp[i][j],tmp[j]);
				}
			}
		}
		printf("%lld\n",dp[n][m]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
