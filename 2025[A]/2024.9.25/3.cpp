#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200009],i,sum,ans;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);sum=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=n-2;i>=1;i--)sum+=a[i];
		a[n-1]-=sum;
		ans=a[n]-a[n-1];
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
