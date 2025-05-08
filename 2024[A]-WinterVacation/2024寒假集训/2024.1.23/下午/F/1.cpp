#include<iostream>
#include<cstdio>
using namespace std;
const long long inf=1e9+7;
long long T,i,n,a3,a2,a1,ANS;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		a3=n;a2=n;a1=n;
		a3*=n;a3%=inf;a2*=n;a2%=inf;
		a3*=n;a3%=inf;
		a3*=4;a2*=3;a1*=1;
        ANS=a3;ANS+=a2;ANS-=a1;
		ANS%=inf;
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
