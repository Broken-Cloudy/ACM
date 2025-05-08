#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a[100009],n,m,i,ans,l,r;
char c;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);ans=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			ans=max(ans,a[i]);
		}
		for(i=1;i<=m;i++){
			getchar();c=getchar();
			scanf("%lld%lld",&l,&r);
			if(ans>=l&&ans<=r&&c=='+')ans++;
			else if(ans>=l&&ans<=r&&c=='-')ans--;
			if(i!=m)printf("%lld ",ans);
			else printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
