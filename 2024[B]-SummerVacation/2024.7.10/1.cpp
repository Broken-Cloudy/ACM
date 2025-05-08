#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9+7;
int T,k,i,j,n,ans,r[5009],Alice;
int cnt,a[5009];
int f[5009],p;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		ans=0;cnt=0;p=0;
		memset(r,0,sizeof(r));
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++){
			scanf("%lld",&k);
			r[k]++;
		}
		for(i=1;i<=n;i++){
			if(r[i]>0){
				a[++cnt]=r[i];
			}
		}
		for(i=1;i<=cnt;i++){
			if(f[p]+a[i]<=i-(p+1)){
				f[p+1]=f[p]+a[i];
				p++;
			}
			for(j=p;j>=1;j--){
				if(f[j-1]+a[i]<=i-j){
					f[j]=min(f[j],f[j-1]+a[i]);
				}
			}
		}
		printf("%lld\n",cnt-p);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
