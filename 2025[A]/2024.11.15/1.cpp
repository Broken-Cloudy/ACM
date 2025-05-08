#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[59],j,kk,f[59],ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)f[i]=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=i-1;j++){
				if(a[i]>=a[j]){
					f[i]=max(f[i],f[j]+1);
				}
			}
		}
		for(i=1;i<=n;i++)ans=max(ans,f[i]);
		printf("%lld\n",n-ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
