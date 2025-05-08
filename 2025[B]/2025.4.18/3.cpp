#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353LL;
int n,m,k,X,ANS,chu2,a[1000009],i,ji,SUM,ks[109];
int x,y,nifac[1000009],fac[1000009],p[1000009],suf[1000009],last,now,j;
void exgcd(int a,int b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;y=t-(a/b)*y;
}
int C(int x,int y){
	if(x<y)return 0LL;
	int ans=fac[x];
	ans*=nifac[y];ans%=P;
	ans*=nifac[x-y];ans%=P;
	return ans;
}
void PRE(){
	exgcd(2LL,P);chu2=(x%P+P)%P;
	fac[0]=nifac[0]=1;
	for(i=1;i<=k;i++){
		fac[i]=fac[i-1]*i;fac[i]%=P;
		exgcd(fac[i],P);
		nifac[i]=(x%P+P)%P;
	}
	ji=1;
	for(i=1;i<=k;i++){
		ji*=chu2;ji%=P;
	}
	for(i=0;i<=k;i++){
		p[i]=C(k,i)*ji;
		p[i]%=P;
	}
	for(i=k;i>=0;i--){
		suf[i]=suf[i+1]+p[i];
		suf[i]%=P;
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>X>>m>>k;
	PRE();
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		SUM+=(a[i]/8192);SUM%=P;
		a[i]%=8192;
	}
	SUM+=(X/8192);X%=8192;
	for(i=0;i<=k;i++){
		ANS+=p[i]*SUM;
		ANS%=P;
	}
	for(i=1;i<=n;i++){
		last=-1;now=a[i];
		ANS+=(now*p[0])%P;
		ANS%=P;
		for(j=1;j<=k;j++){
			now=now+(now&m)+X;
			if(last==now){
				ANS+=ks[j];
				now%=8192;ANS%=P;
				ANS+=(now*suf[j])%P;ANS%=P;
				break;
			}
			else{
				last=now;
				ANS+=suf[j]*(now/8192);now%=8192;ANS%=P;
				ANS+=(now*p[j])%P;ANS%=P;
			}
		}
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
