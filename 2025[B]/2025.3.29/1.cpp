#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[109],x,y;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		x=1999999999LL;y=-1;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			x=min(x,a[i]);
			y=max(y,a[i]);
		}
		printf("%lld\n",y-x);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
