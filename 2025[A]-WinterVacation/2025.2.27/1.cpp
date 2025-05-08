#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		ans=n/15*3;
		n%=15;
		if(n==0)ans+=1;
		else if(n==1)ans+=2;
		else ans+=3;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
