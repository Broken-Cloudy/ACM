#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a,b,c,d,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		ans=min(a*c+b*d,(a+b)*d);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
