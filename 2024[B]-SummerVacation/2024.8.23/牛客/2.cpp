#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,t,ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		while(n>0){
			t=n/2+1;
			n-=t;
			ans++;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
