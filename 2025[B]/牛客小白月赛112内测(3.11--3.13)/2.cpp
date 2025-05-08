#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100009],i,ans=-1;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=2;i<n;i++){
		if(a[i]>a[i-1]&&a[i]>a[i+1]){
			ans=max(ans,a[i]-(a[i-1]+a[i+1])/2);
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
