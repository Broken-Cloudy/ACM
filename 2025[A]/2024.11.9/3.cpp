#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[300009],i,ans0,ans1,ansnow,T,ans;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans0=0;ans1=-99999999;ansnow=-1;ans=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			ans1=max(ans1,ansnow);
			if(a[i]>ans1){
				ans1++;
			}
			else if(a[i]<ans1){
				ans1--;
			}
			if(a[i]>ans0){
				ans0++;
			}
			else if(a[i]<ans0){
				ans0--;
			}
			ansnow=max(ansnow,ans0);
		}
		ans=max(ans,ans0);
		ans=max(ans,ansnow);
		ans=max(ans,ans1);
		if(ans==n)ans--;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
