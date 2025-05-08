#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,r,c,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		scanf("%lld%lld%lld%lld",&n,&m,&r,&c);
		ans+=(n-r)*(m-1);
		ans+=1*(n-r)*m;
		ans+=(m-c);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
