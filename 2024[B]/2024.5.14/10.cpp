#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,a[200009],i,ans,t,vis[200009];
signed main(){
	freopen("10.in","r",stdin);freopen("10.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		ans=1;
		scanf("%lld%lld",&n,&x);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		t=x;
		while(vis[t]==0){
			vis[t]=ans;
			ans++;
			t=a[t];
		}
		printf("%lld\n",vis[t]-1);
		for(i=1;i<=n;i++)vis[i]=0,a[i]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
