#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000009],i,f[1000009][3],cnt[1000009][3];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++){
		if(i%2==0)cnt[i][0]++;
		else cnt[i][1]++;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
