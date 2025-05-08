#include<iostream>
#define ll long long
using namespace std;
ll T,n,m,mod,k,i,C1,C2,r,x,y,ans;
ll fac[200009],nfac[200009];
void exgcd(ll a,ll b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	ll t=x;
	x=y;y=t-(a/b)*y;
}
ll CC(ll x,ll y){
	ll ANS=fac[x];
	ANS*=nfac[y];
	ANS%=mod;
	ANS*=nfac[x-y];
	ANS%=mod;
	return ANS;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&mod);
		fac[0]=1;nfac[0]=1;
		for(i=1;i<=200001;i++){
			fac[i]=fac[i-1]*i;
			fac[i]%=mod;
			exgcd(fac[i],mod);
			nfac[i]=((x%mod)+mod)%mod;
		}
		ans=CC(n+m,m);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
