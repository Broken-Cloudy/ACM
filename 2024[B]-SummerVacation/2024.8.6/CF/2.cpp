#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a1,a2,b1,b2,ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld%lld",&a1,&a2,&b1,&b2);
		ans=0;
		if(a1>b1&&a2>b2)ans++;
		else if((a1==b1&&a2>b2)||(a1>b1&&a2==b2))ans++;
		if(a1>b2&&a2>b1)ans++;
		else if((a1==b2&&a2>b1)||(a1>b2&&a2==b1))ans++;
		if(a2>b1&&a1>b2)ans++;
		else if((a2==b1&&a1>b2)||(a2>b1&&a1==b2))ans++;
		if(a2>b2&&a1>b1)ans++;
		else if((a2==b2&&a1>b1)||(a2>b2&&a1==b1))ans++;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
