#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,ans,pp,n,k;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);
		ans=n/(k-1);n-=n/(k-1)*(k-1);
		if(n>1)ans++;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
