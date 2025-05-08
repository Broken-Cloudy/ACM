#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a,b,c,ans,k;
signed main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&a,&b,&c);
		ans=a+b+c;
		if(ans%3==0){
			k=ans/3;
			if(a<=k&&b<=k)printf("YES\n");
			else printf("NO\n");
		}
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
