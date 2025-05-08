#include<bits/stdc++.h>
#define int long long
#define __int128 long long
using namespace std;
int k,a,b,T,aa,bb,kk,GCD,A,B,i,x,y,I;
__int128 ans,AA,BB,II;
void gcd(__int128 a,__int128 b){
	if(b==0){
		GCD=a;
		return;
	}
	gcd(b,a%b);
}
void putout(__int128 x){
	char c;
	if(x==0)return;
	putout(x/10);
	c=x%10+'0';
	putchar(c);
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&aa,&bb,&kk);
		a=max(aa,bb);b=min(aa,bb);k=kk;
		ans=100000000000000000LL;ans=ans*ans;
		if(k>=a-b){
			putout(a);putchar('\n');
			continue;
		}
		for(I=1;I<=(a+(I-1))/I;I++){
			i=I;
			x=(i-a%i)%i;y=(i-b%i)%i;
			A=a+x;
			B=b+y;
			if(x<=k&&y<=k){
				AA=A;BB=B;II=i;
				ans=min(ans,AA*BB/II);
			}
			i=A/i;x=(i-a%i)%i;y=(i-b%i)%i;
			A=a+x;
			B=b+y;
			if(x<=k&&y<=k){
				AA=A;BB=B;II=i;
				ans=min(ans,AA*BB/II);
			}
			i=I;x=(i-a%i)%i;y=(i-b%i)%i;A=a+x;B=b+y;
			i=B/i;x=(i-a%i)%i;y=(i-b%i)%i;
			A=a+x;
			B=b+y;
			if(x<=k&&y<=k){
				AA=A;BB=B;II=i;
				ans=min(ans,AA*BB/II);
			}
		}
		putout(ans);putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
