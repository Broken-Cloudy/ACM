#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,n,k,ans;
long double S,ANS,dd;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);dd=1.0;S=(n+1.0)/2.0;ANS=0.0;
		while(n>=k){
			if(n%2==1){
				ANS+=dd*S;
				n=(n+1)/2;
				n--;
			}
			else{
				n/=2;
			}
			dd*=2.0;
		}
		ans=ANS;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
