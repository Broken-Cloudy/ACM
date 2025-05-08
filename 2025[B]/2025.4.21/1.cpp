#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[109],b[109],ans;
signed main(){
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			b[a[i]]=1;
		}
		for(i=1;i<=100;i++){
			if(b[i]==1)ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
