#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,i;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);
		if(k%2==1){
			for(i=1;i<=n;i++){
				if(i==n)printf("%lld\n",n-1);
				else printf("%lld ",n);
			}
		}
		else{
			for(i=1;i<=n;i++){
				if(i==n-1)printf("%lld ",n);
				else if(i==n)printf("%lld\n",n-1);
				else printf("%lld ",n-1);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
