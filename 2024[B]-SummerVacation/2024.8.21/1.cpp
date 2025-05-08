#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,a[1009],k,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=n;i++)a[i]=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&k);
			a[k]++;
		}
		for(i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		printf("%lld\n",n-ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
