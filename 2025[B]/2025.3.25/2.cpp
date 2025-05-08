#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1000000007LL;
int n,k,fac[100009],nifac[100009],ANS,i,j,x,y,anss;
int C(int x,int y){
	if(x<y)return 0LL;
	int ans;
	ans=fac[x];
	ans*=nifac[y];ans%=P;
	ans*=nifac[x-y];ans%=P;
	return ans;
}
int ksm(int a,int p){
	int kk=1;
	while(p>1){
		if(p%2==1){
			kk*=a;kk%=P;
		}
		a*=a;a%=P;p/=2;
	}
	kk*=a;kk%=P;
	return kk;
}
void exgcd(int a,int b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;y=t-(a/b)*y;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>k;
	fac[0]=1;nifac[0]=1;
	for(i=1;i<=100000;i++){
		fac[i]=fac[i-1]*i;fac[i]%=P;
		exgcd(fac[i],P);
		nifac[i]=(x%P+P)%P;
	}
	ANS=nifac[k];
	for(i=0;i<=k;i++){
		if((k-i)%2==0){
			anss+=(C(k,i)*ksm(i,n));
		}
		else{
			anss-=(C(k,i)*ksm(i,n));
		}
		anss=(anss%P+P)%P;
	}
	ANS*=anss;ANS%=P;
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
