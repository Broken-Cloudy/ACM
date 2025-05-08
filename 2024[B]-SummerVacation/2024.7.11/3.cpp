#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[100009],i,cnt,ans;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		ans=0;
		for(i=n;i>=1;i--){
			if(a[i]>ans){
				ans=a[i];
			}
			else{
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
