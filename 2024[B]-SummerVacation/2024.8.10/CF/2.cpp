#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a[200009],n,i;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		printf("%lld ",a[n]);
		for(i=1;i<n;i++){
			if(i==n-1)printf("%lld\n",a[i]);
			else printf("%lld ",a[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
