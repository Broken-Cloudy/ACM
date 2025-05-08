#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,X,Y,K,R;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&X,&Y,&K);
		R=min(X,Y);
		printf("%lld %lld ",0LL,0LL);
		printf("%lld %lld\n",R,R);
		printf("%lld %lld ",R,0LL);
		printf("%lld %lld\n",0LL,R);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
