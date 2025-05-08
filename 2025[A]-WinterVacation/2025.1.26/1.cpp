#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,m,k,a[100009],b[100009];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=m;i++)scanf("%lld",&b[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
