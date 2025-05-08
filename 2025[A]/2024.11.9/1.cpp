#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,l,r,k,ans,R;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&l,&r,&k);
		if(k==1){
			ans=r-l+1;
			printf("%lld\n",ans);
		}
		else{
			R=r/k;
			ans=(R-l+1);
			ans=max(0LL,ans);
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
