#include<bits/stdc++.h>
using namespace std;
const long long inf=1000000007;
struct nod{
	long long a,b;//小红胜利 
};
nod f[1009][1009];
long long x,y,n,k,num1,num2,i,j;
long long GCD;
void exgcd(long long a,long long b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;y=t-(a/b)*y;
}
void gcd(long long a,long long b){
	if(b==0){
		GCD=a;
		return;
	}
	gcd(b,a%b);
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	f[1][0].a=1;f[1][0].b=1;f[0][1].a=0;f[0][1].b=1;
	for(i=1;i<=1000;i++)f[i][0].a=1,f[i][0].b=1;
	for(i=2;i<=1000;i++){//个数 
		for(j=1;j<=i;j++){//2的个数 
			if(j==i){
				long long bb=f[1][j-1].b;
				long long aa=bb-f[1][j-1].a;
				f[0][j].a=aa;
				f[0][j].b=bb;
			}
			else{
				long long a1=f[i-j+1][j-1].b-f[i-j+1][j-1].a;
				long long b1=f[i-j+1][j-1].b;
				long long a2=f[i-j-1][j].b-f[i-j-1][j].a;
				long long b2=f[i-j-1][j].b;
				a1*=j;b1*=i;//2的个数
				a1%=inf;b1%=inf;
				a2*=(i-j);b2*=i;//1的个数 
				a2%=inf;b2%=inf;
				long long b=b1*b2;
				long long a=a1*b2+a2*b1;
				a%=inf;b%=inf;
				f[i-j][j].a=a;
				f[i-j][j].b=b;
			}
		}
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&k);
		if(k==1){
			num1++;
		}
		else{
			num2++;
		}
	}
	//有理数取余部分 
	long long a=f[num1][num2].a,b=f[num1][num2].b;
	exgcd(b,inf);//(1/b)%inf*a
	cout<<((x%inf)*(a%inf)%inf+inf)%inf<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
