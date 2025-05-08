#include<bits/stdc++.h>
#define int long long 
using namespace std;
int T,n,m,a,b;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
		a=!a;b=!b;
		if(a==1&&b==1){
			if((n==1&&m==2)||(n==2&&m==1)){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
		}
		else if(a==1){
			if(n==2||m==2){
				printf("Yes\n");
			}
			else if(n==1||m==1){
				printf("No\n");
			}
			else{
				if(n%2!=0&&m%2!=0){
					printf("No\n");
				}
				else{
					printf("Yes\n");
				}
			}
		}
		else if(b==1){
			if(n==1||m==1){
				if(n%2!=0&&m%2!=0){
					printf("No\n");
				}
				else{
					printf("Yes\n");
				}
			}
			else{
				printf("No\n");
			}
		}
		else{
			if(n%2!=0&&m%2!=0){
				printf("No\n");
			}
			else{
				printf("Yes\n");
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
