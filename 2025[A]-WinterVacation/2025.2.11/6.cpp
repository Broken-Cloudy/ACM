#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1000000000000000009LL;
int T,i,x,y,f[1009][2],n,j,a[1009],b[1009],ans;
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&x,&y);
		for(i=1;i<=n;i++){
			scanf("%lld%lld",&a[i],&b[i]);
			f[i][1]=f[i][0]=inf;
		}
		for(i=1;i<=n;i++){
			for(j=0;j<i;j++){
				if(a[i]>=a[j]&&b[i]>=b[j]){
					f[i][0]=min(f[j][0]+(i-j-1)*x,f[i][0]);
					f[i][1]=min(f[j][1]+(i-j-1)*x+y,f[i][1]);
				}
				if(a[i]>=b[j]&&b[i]>=a[j]){
					f[i][0]=min(f[j][1]+(i-j-1)*x,f[i][0]);
					f[i][1]=min(f[j][0]+(i-j-1)*x+y,f[i][1]);
				}
			}
		}
		ans=inf;
		for(j=0;j<=n;j++){
			ans=min(ans,f[j][0]+(n+1-j-1)*x);
			ans=min(ans,f[j][1]+(n+1-j-1)*x);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
