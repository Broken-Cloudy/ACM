#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,a[2009],f[2009],num,ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=1;i<=n;i++){
			num=1;f[i]=1;
			for(j=i-1;j>=1;j--){
				if(a[j]<a[i])num++;
				else{
					f[i]=max(f[i],f[j]+num);
				}
			}
		}
		for(i=1;i<=n;i++){
			ans=max(ans,f[i]);
		}
		printf("%lld\n",n-ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
