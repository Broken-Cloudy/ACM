#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,k,ans,i,j;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		if(n/(m+1)>=k){
			for(j=1;j<=m+1;j++){
				for(i=0;i<n/(m+1);i++){
					printf("%lld ",i);
				}
			}
			for(j=1;j<=n%(m+1);j++){
				printf("1000000000 ");
			}
		}
		else{
			for(i=0;i<n;i++){
				printf("%lld ",i%k);
			}
		}
		printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
