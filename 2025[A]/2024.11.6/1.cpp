#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=100000000000000009LL;
int i,n,m,T,a[300009],b[300009],f[300009],sum[300009],j,d;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)f[i]=inf;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		for(i=1;i<=m;i++)scanf("%lld",&b[i]);
		for(i=1;i<=m;i++){//b
			for(j=1;j<=n;j++){//a
				d=lower_bound(sum,sum+1+n,sum[j]-b[i])-sum;
				f[j]=min(f[j],f[d]+(m-i));
			}
		}
		if(f[n]==inf)printf("-1\n");
		else printf("%lld\n",f[n]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
