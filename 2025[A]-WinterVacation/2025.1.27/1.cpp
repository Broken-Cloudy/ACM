#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,m,k,a[100009],b[19],j,maxx,ans,w[100009][12];
int dp[1027],num[1027];
int p[12];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=m;i++)scanf("%lld",&b[i]);
		for(i=0;i<=(1LL<<m)-1LL;i++){
			dp[i]=(1LL<<36LL)-1LL;
			num[i]=0;
		}
		dp[0]=0;
		for(i=0;i<=(1LL<<m)-1LL;i++){
			for(j=1;j<=m;j++){
				if(i&(1LL<<(j-1))){
					num[i]++;
					dp[i]=dp[i]&b[j];
				}
			}
		}
		for(i=1;i<=n;i++){//100000
			for(j=0;j<=(1LL<<m)-1LL;j++){//1024
				w[i][num[j]]=max(w[i][num[j]],(a[i]-a[i]&dp[j]));
			}
		}
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
