#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1e9+7;
int T,n,i,ANS;
char c[200009];
int check(){
	int i,anss=1;
	if(c[1]!=c[n]){
		for(i=2;i<n;i++){
			if(c[i]=='?'){
				anss*=2;
				anss%=P;
			}
		}
		anss*=2;anss%=P;
	}
	else{
		for(i=2;i<n;i++){
			if(c[i]=='?'){
				anss*=2;
				anss%=P;
			}
		}
		anss*=(n-2);anss%=P;
	}
	return anss;
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);getchar();ANS=0;
		for(i=1;i<=n;i++)c[i]=getchar();
		if(n==1){
			if(c[1]!='?')printf("1\n");
			else printf("2\n");
			continue;
		}
		if(c[1]=='?'&&c[n]=='?'){
			c[1]='0';c[n]='1';
			ANS+=check();ANS%=P;
			c[1]='1';c[n]='1';
			ANS+=check();ANS%=P;
			c[1]='1';c[n]='0';
			ANS+=check();ANS%=P;
			c[1]='0';c[n]='0';
			ANS+=check();ANS%=P;
		}
		else if(c[1]=='?'){
			c[1]='0';
			ANS+=check();ANS%=P;
			c[1]='1';
			ANS+=check();ANS%=P;
		}
		else if(c[n]=='?'){
			c[n]='0';
			ANS+=check();ANS%=P;
			c[n]='1';
			ANS+=check();ANS%=P;
		}
		else{
			ANS+=check();ANS%=P;
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
