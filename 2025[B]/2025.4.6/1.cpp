#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353LL;
int T,i,j,a[29],f[250009],n,m,SUM,x,y,sum,k;
int nifac[500009],fac[500009];
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
	for(i=1;i<=500000;i++){
		fac[i]=fac[i-1]*i;fac[i]%=P;
		exgcd(fac[i],P);nifac[i]=(x%P+P)%P;
	}
	cin>>T;
	while(T--){
		SUM=0;
		for(i=1;i<=26;i++){
			scanf("%lld",&a[i]);
			SUM+=a[i];
		}
		n=(SUM+1)/2;m=SUM/2;sum=0;
		for(i=1;i<=n;i++)f[i]=0;f[0]=1;
		for(i=1;i<=26;i++){
			if(a[i]==0)continue;
			sum+=a[i];
			for(j=n;j>=0;j--){
				k=sum-j;//选择给m的容量 
				f[j]*=C(k,a[i]);
				f[j]%=P;
				if(j>=a[i]){
					f[j]+=(f[j-a[i]])*C(j,a[i])%P;//选给n 
					f[j]%=P;
				}
			}
		}
		printf("%lld\n",f[n]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
