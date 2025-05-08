#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[109],i,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		ans=0;
		for(i=1;i<=n;i+=2)ans=max(ans,a[i]);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
