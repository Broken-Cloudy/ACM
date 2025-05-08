#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,l,r,d,u;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld%lld",&l,&r,&d,&u);
		if(l==r&&r==d&&d==u)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
