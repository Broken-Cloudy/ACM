#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353LL;
int T,x,y,i;
int nifac[250009],fac[250009];
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
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	nifac[0]=fac[0]=1;
	for(i=1;i<=250009;i++){
		fac[i]=fac[i-1]*i;
		fac[i]%=P;
		exgcd(fac[i],P);
		nifac[i]=(x%P+P)%P;
	}
	cin>>T;
	while(T--){
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
