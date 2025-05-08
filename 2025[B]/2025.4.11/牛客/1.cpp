#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[18],i;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	a[1]=(a[1]-1+2);
	for(i=2;i<=n;i++){
		a[i]=min(5LL,a[i]-1);
	}
	for(i=1;i<=n;i++)printf("%lld ",a[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
