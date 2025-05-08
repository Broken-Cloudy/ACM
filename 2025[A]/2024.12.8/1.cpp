#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,m,k,a[100009],i,j,ANS,PP,ans,sum,rr,kk,kkn,o;
int x,y,nfac[64];
long long fff(long long a,long long b,long long p){
	long long kk=1;
	while(b!=1){
		if(b%2==0){
			a=(a%p)*(a%p)%p;
			b/=2;
		}
		else if(b%2==1){
			kk*=a;kk%=p;
			a=(a%p)*(a%p)%p;
			b-=1;b/=2;
		}
	}
	return (a%p)*(kk%p)%p;
}
void exgcd(long long a,long long b){
	if(b==0){
		x=1;y=0;
		//gcd=a;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;y=t-(a/b)*y;
}
int C(int x,int k){
	int ii,ans=1;
	if(x==0)return 1LL;
	else if(x==k)return 1LL;
	else{
		for(ii=k;ii>k-x;ii--){
			ans*=ii;ans%=mod;
		}
		for(ii=1;ii<=x;ii++){
			ans*=nfac[ii];ans%=mod;
		}
		return ans;
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	nfac[0]=1;
	for(i=1;i<=61;i++){
		exgcd(i,mod);
		nfac[i]=((x%mod)+mod)%mod;
	}
	cin>>n>>m>>k;
	kk=fff(2LL,k,mod);kk%=mod;
	kkn=fff(nfac[2],k,mod);kkn%=mod;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(o=1;o<=n;o++){
		for(i=0;i<=k;i++){
				if(i>=32){
					PP=0;
					for(j=0;j<=31;j++){
						PP+=C(j,k);
						PP%=mod;
					}
					PP=(kk-PP+mod)%mod;
					ANS+=(PP*rr)%mod;
					break;
				}
				else if(i<=30){
					sum=a[o];
					sum%=mod;sum*=C(i,k);sum%=mod;
					ANS+=sum;ANS%=mod;
					a[o]+=a[o]&m;
				}
				else{
					sum=a[o];
					sum%=mod;rr=sum;
					sum*=C(i,k);sum%=mod;
					ANS+=sum;ANS%=mod;
				}
			}
	}
	
	ANS*=kkn;ANS%=mod;
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
