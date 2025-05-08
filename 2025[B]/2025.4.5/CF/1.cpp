#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		if(n%2==0){
			printf("-1\n");
		}
		else{
			printf("%lld 1",n);
			for(i=2;i<=n-1;i++){
				if(i==n-1)printf(" %lld\n",i);
				else printf(" %lld",i);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
