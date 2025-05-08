#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353LL;
int n,m,x,y,i,j,fac[100009],nifac[100009],anss,ans,t;
void exgcd(int a,int b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;y=t-(a/b)*y;
}
void Pre(){
	fac[0]=nifac[0]=1;
	for(int i=1;i<=100000;i++){
		fac[i]=fac[i-1]*i;fac[i]%=P;
		exgcd(fac[i],P);
		nifac[i]=(x%P+P)%P;
	}
}
int CC(int x,int y){
	if(y>x)return 0LL;
	int ANS;
	ANS=fac[x];
	ANS*=nifac[x];ANS%=P;
	ANS*=nifac[x-y];ANS%=P;
	return ANS;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	Pre();
	cin>>n>>m;
	anss=CC(m,n);
	for(x=1;x<=n;x++){
		t=x;
		for(i=2;i*i<=x;i++){
			while()
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
