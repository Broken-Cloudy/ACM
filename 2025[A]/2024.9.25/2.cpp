#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y,ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&x,&y);
		ans=(n+min(x,y)-1)/min(x,y);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
