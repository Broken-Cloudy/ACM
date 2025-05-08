#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,c0,c1,ans,a[200009];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);c0=c1=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			if(a[i]%2==0){
				c0++;
			}
			else c1++;
		}
		if(c0>=1)ans=c1+1;
		else ans=c1-1;
		ans=max(0LL,ans);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
