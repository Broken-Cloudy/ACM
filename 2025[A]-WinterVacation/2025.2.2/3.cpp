#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,j,i,n,a[309][309],f[309],ans,t1,t2;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=1;
		for(i=1;i<=n;i++)f[i]=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		for(i=1;i<=n;i++){
			for(j=n;j>=1;j--){
				if(a[i][j]==1)f[i]++;
				else break;
			}
		}
		sort(f+1,f+1+n);
		for(i=1;i<=n;i++){
			if(f[i]>=ans){
				ans++;
			}
		}
		ans=min(ans,n);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
