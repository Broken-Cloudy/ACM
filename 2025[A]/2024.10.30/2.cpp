#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1||n==3)printf("%lld\n",-1LL);
		else{
			if(n%2==0){
				n-=2;
				for(i=1;i<=n;i++){
					putchar('3');
				}
				printf("66");
				putchar('\n');
			}
			else{
				n-=5;
				for(i=1;i<=n;i++){
					putchar('3');
				}
				printf("36366");
				putchar('\n');
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
