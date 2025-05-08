#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,w,h,W,H,i,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);W=H=0;
		for(i=1;i<=n;i++){
			scanf("%lld%lld",&w,&h);
			W=max(W,w);H=max(H,h);
		}
		ans=2*(W+H);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
