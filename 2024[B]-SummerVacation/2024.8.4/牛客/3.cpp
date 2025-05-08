#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int,int>ha;
int n,m,a[100009],i,ans;
signed main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	ha[0]=100000009;
	for(i=1;i<=n;i++){
		if(ha[a[i]-1]>0){
			ha[a[i]-1]--;
			ha[a[i]]++;
			ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
