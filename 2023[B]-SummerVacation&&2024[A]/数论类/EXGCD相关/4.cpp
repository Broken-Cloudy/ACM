#include<iostream>
#include<cstdio>
using namespace std;
long long sum,m,kk,N1,N2,gcd,GCD;
long long x1,y1,x2,y2,ans,k3,r1,r2;
int i,n;
void exgcd(long long a,long long b){
	if(b==0){
		x1=1;y1=0;
		gcd=a;
		return;
	}
	exgcd(b,a%b);
	long long t=x1;x1=y1;
	y1=t-(a/b)*y1;
}
void EXGCD(long long a,long long b){
	if(b==0){
		x2=1;y2=0;
		GCD=a;
		return;
	}
	EXGCD(b,a%b);
	long long t=x2;x2=y2;
	y2=t-(a/b)*y2;
}
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%lld",&kk);
		sum+=kk;
	}
	N1=n;N2=(1+n)*n/2;
	exgcd(N1,N2);
	EXGCD(gcd,m);
	k3=sum/GCD;
	ans=sum-k3*GCD;
	x2=((x2%m)+m)%m;
	x2*=-((k3%m)+m)%m;
	x2=((x2%m)+m)%m;
	x1=(x1%m+m)%m;y1=(y1%m+m)%m;
	x1*=x2;y1*=x2;
	x1=(x1%m+m)%m;y1=(y1%m+m)%m;
	cout<<ans<<endl;
	cout<<x1<<' '<<y1<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
} 
