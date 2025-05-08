#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,k;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);
		if(n==1){
			printf("1\n");
			printf("1\n");
		}
		else if(n==3){
			if(k==2){
				printf("3\n");
				printf("1 2 3\n");
			}
			else{
				printf("-1\n");
			}
		}
		else{
			if(k==1||k==n)printf("-1\n");
			else if(k%2==1){
				printf("5\n");
				printf("%lld %lld %lld %lld %lld\n",1LL,2LL,k,k+1LL,n);
			}
			else{
				printf("3\n");
				printf("%lld %lld %lld\n",1LL,k,k+1LL);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
