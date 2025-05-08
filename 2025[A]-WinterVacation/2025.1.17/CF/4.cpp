#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,i,n,a[100009],ans;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i+=2){
			ans+=(n-i+1);
		}
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
