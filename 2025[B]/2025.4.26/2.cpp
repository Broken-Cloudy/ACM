#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,i,a[100009],b,c,d,ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		d=(n-k+1)/2;
		b=a[d];
		c=a[n-d+1];
		ans=c-b+1;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
