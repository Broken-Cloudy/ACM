#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18+9;
int T,a[209][209],i,j,n,m,t,k,dp[209][209][409],val,x,y;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				for(t=1;t<=n+m;t++)dp[i][j][t]=INF;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				for(t=i-1;t<=i-1+m-1;t++){
					val=abs(t-(i+j-2))*k;
					if(t>0){
						dp[i][j][t]=min(dp[i][j][t],dp[x][y][t-1]+val);
					}
					else dp[i][j][t]=val;
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
