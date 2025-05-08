#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,m,k,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		ans=min(k*k,min(k*n,k*m));
		ans=min(ans,n*m);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
