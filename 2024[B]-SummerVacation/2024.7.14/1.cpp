#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int T,n,i,j,C[5009][5009],a,b,subz,k,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	C[0][0]=C[1][0]=C[1][1]=1;
	for(i=1;i<=5000;i++){//O(N2)
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		ans=0;
		for(subz=0;subz<=n;subz++){
			for(k=1;k<=2*n+1;k++){
				a=k-subz-1;b=subz-a;
				if(min(a,b)>=0){
					ans+=(C[min(k-1,n)][a]*C[max(0LL,n-k)][b]%mod*k)%mod;
					ans%=mod;
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
