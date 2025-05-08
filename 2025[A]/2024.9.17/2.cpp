#include<iostream>
#define ll long long
using namespace std;
ll T,n,k,i,C1,C2,r,x,y,ans1,ans2,ANS;
ll fac[100009],nfac[100009];
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
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	if(n==2){
		cout<<1<<endl;
	}
	else if(n==4){
		cout<<2<<endl;
	}
	else{
		n-=2;
		fac[0]=1;nfac[0]=1;
		for(i=1;i<=100001;i++){
			fac[i]=fac[i-1]*i;
			fac[i]%=mod;
			exgcd(fac[i],mod);
			nfac[i]=((x%mod)+mod)%mod;
		}
		ans1=CC(n,n/2);
		ans2=CC(n,n/2-2);
		ANS=(ans1-ans2+mod)%mod;
		cout<<ANS<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
