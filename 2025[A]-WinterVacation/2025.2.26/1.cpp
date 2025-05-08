#include<bits/stdc++.h>
#define int long long
using namespace std;
int X,Y,ANS;
bool F;
void kk(int x){
	if(x>=100)printf("%lld",x);
	else if(x>=10)printf("0%lld",x);
	else printf("00%lld",x);
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>X>>Y;
	ANS=X+Y;
	if(abs(ANS)>=1000000){
		if(ANS<0)F=1;
		else F=0;
		ANS=abs(ANS);
		if(F==1)putchar('-');
		printf("%lld",ANS/1000000);putchar(',');kk(ANS/1000%1000);
		putchar(',');kk(ANS%1000);
	}
	else if(abs(ANS)>=1000){
		if(ANS<0)F=1;
		else F=0;
		ANS=abs(ANS);
		if(F==1)putchar('-');
		printf("%lld",ANS/1000%1000);putchar(',');kk(ANS%1000);
	}
	else{
		if(ANS<0)F=1;
		else F=0;
		ANS=abs(ANS);
		if(F==1)putchar('-');
		printf("%lld",ANS%1000);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
