#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,m,q;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&m,&k,&q);
		if((n-q)%k==0&&q<=m*(k-1))printf("Yes\n");
		else printf("No\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
