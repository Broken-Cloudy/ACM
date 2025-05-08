#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,ANS,uu;
char c[100009];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);getchar();ANS=0;uu=0;
		for(i=1;i<=n;i++)c[i]=getchar();
		for(i=1;i<=n;i++){
			if(i>=3){
				if(c[i-2]=='u')uu++;
			}
			if(i+7<=n){
				if(c[i]=='u'&&c[i+1]=='w'&&c[i+2]=='a'&&c[i+3]=='w'){
					if(c[i+4]=='a'&&c[i+5]=='u'&&c[i+6]=='w'&&c[i+7]=='a'){
						ANS+=uu;
					}
				}
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
