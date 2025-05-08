#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[2009],i,k1,k2,ans,b[2009],bcnt,j;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);k1=0;
		if(n==1){
			scanf("%lld",&a[1]);
			printf("%lld\n",1LL);
		}
		else if(n%2==1){
			ans=1000000000000000009LL;
			for(i=1;i<=n;i++)scanf("%lld",&a[i]);
			for(i=1;i<=n;i++){
				bcnt=0;k1=0;
				for(j=1;j<=n;j++){
					if(i!=j){
						b[++bcnt]=a[j];
					}
				}
				for(j=2;j<=bcnt;j+=2){
					k1=max(k1,b[j]-b[j-1]);
				}
				ans=min(k1,ans);
			}
			printf("%lld\n",ans);
		}
		else{
			for(i=1;i<=n;i++)scanf("%lld",&a[i]);
			for(i=2;i<=n;i+=2){
				k1=max(k1,a[i]-a[i-1]);
			}
			ans=k1;
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
