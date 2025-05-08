#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,n,i;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		if(n==1){
			printf("1\n");printf("1\n");
		}
		else if(n==2){
			printf("2\n");printf("1 2\n");
		}
		else if(n==3){
			printf("2\n");printf("1 2 2\n");
		}
		else if(n==4){
			printf("3\n");printf("1 2 2 3\n");
		}
		else if(n==5){
			printf("3\n");printf("1 2 2 3 3\n");
		}
		else{
			printf("4\n");
			for(i=1;i<=n;i++){
				if(i==n)printf("%lld\n",i%4+1);
				else printf("%lld ",i%4+1);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
