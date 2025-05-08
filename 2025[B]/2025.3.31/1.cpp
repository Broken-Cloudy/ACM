#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[500009];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
