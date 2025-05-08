#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a[209][209],i,j,n,m,t,k,dp[209][209][209],ans;
const int INF=1e18+7;
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
		for(t=0;t<m;t++){
			dp[1][1][t]=k*t+a[1][t%m+1];
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				for(t=0;t<m;t++){
					if(dp[i][j][t]==INF)continue;
					if(j<m){
						int val=a[i][(j+t)%m+1];
						if(dp[i][j+1][t]>dp[i][j][t]+val){
							dp[i][j+1][t]=dp[i][j][t]+val;
						}
					}
					if(i<n){
                    	for(int t_next=0;t_next<m;t_next++){
                     		int pos=(j+t_next-1)%m;
                        	if(pos<0)pos+=m;
                        	pos+=1;
                        	int val=a[i+1][pos];
                        	int cost=dp[i][j][t]+k*t_next+val;
                        	if(dp[i+1][j][t_next]>cost){
                        	    dp[i+1][j][t_next]=cost;
                        	}
                    	}
                	}
				}
			}
		}
		ans=INF;
		for(t=0;t<m;t++){
			ans=min(ans,dp[n][m][t]);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
