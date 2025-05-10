#include<iostream>
#define ll long long
using namespace std;
ll T,n,k,i,C1,C2,r,x,y,ans,sum;
ll fac[200009],nfac[200009];
const ll mod=1000000007;
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
//	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	fac[0]=1;nfac[0]=1;
	for(i=1;i<=200001;i++){
		fac[i]=fac[i-1]*i;
		fac[i]%=mod;
		exgcd(fac[i],mod);
		nfac[i]=((x%mod)+mod)%mod;
	}
	while(T--){
		scanf("%lld%lld",&n,&k);
		C1=C2=0;ans=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&r);
			if(r==1)C1++;
			else C2++;
		}
		for(i=k;i>=k/2+1;i--){
			sum=0;
			if(C1>=i&&C2>=(k-i)){
				sum=CC(C1,i);
				sum*=CC(C2,k-i);
				sum%=mod;
				ans+=sum;
				ans%=mod;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
