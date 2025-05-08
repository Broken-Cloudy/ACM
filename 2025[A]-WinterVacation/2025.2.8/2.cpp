#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a,b,c,ans,kk;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&a,&b,&c);ans=0;
		kk=a-c;ans=kk/b;ans=min(ans,c+1);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
