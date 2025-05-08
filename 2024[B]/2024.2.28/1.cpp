#include<bits/stdc++.h>
using namespace std;
const long long inf=1000000007;
long long f[2009][2009],i,j,x,y,a,b,A,B,ans1,ans2,ans;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>x>>y;
	f[0][0]=f[1][0]=f[0][1]=f[1][1]=1;
	for(i=2;i<=2000;i++){
		f[i][0]=1;
		for(j=1;j<=i;j++){
			f[i][j]=(f[i-1][j-1]+f[i-1][j])%inf;
		}
	}
	a=1;b=0;A=0;B=1;
	printf("0\n");
	while(a+b<x+y){
		ans1=0;ans2=0;
		if((a+b)%2==0){
			a++;B++;
			ans1=f[x-1][a-1];
			ans1*=f[y-1][b-1];
			ans1%=inf;
			if(a>x||b>y)ans1=0;
			ans2=f[x-1][A-1];
			ans2*=f[y-1][B-1];
			ans2%=inf;
			if(A>x||B>y)ans2=0;
		}
		else{
			b++;A++;
			ans1=f[x-1][a-1];
			ans1*=f[y-1][b-1];
			ans1%=inf;
			if(a>x||b>y)ans1=0;
			ans2=f[x-1][A-1];
			ans2*=f[y-1][B-1];
			ans2%=inf;
			if(A>x||B>y)ans2=0;
		}
		ans=(ans1+ans2)%inf;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
