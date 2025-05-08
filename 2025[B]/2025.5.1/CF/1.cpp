#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,n,i,j,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1,j=n;i<=n;i++,j--){
			ans+=abs(i-j);
		}
		printf("%lld\n",ans/2+1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
