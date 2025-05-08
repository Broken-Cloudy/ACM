#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a,b,c,GCD,k1,k2;
int f1,f2,f3;
void gcd(int a,int b){
	if(b==0){
		GCD=a;
	}
	else gcd(b,a%b);
}
signed main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	cin>>T;
	while(T--){
		f1=f2=f3=0;
		scanf("%lld%lld%lld",&a,&b,&c);
		gcd(a,b);if(GCD==1)f1++;
		gcd(c,b);if(GCD==1)f2++;
		gcd(a,c);if(GCD==1)f3++;
		if(f1+f2+f3!=2){
			printf("%lld %lld %lld\n",a,b,c);
			k1++;
		}
		else{
			k2++;
		}	
	}
	printf("YES:%lld\n",k2);printf("NO:%lld\n",k1);
	fclose(stdin);fclose(stdout);
	return 0;
}
