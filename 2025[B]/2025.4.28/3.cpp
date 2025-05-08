#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[200009],f[200009],sum[200009],SUM;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);SUM=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		f[1]=a[1];for(i=2;i<=n;i++)f[i]=max(a[i],f[i-1]);
		for(i=n;i>=1;i--){
			SUM+=a[i];
			if(a[i]<=f[i-1]){
				SUM-=a[i];
				SUM+=f[i-1];
				sum[n-i+1]=SUM;
				SUM+=a[i];
				SUM-=f[i-1];
			}
			else sum[n-i+1]=SUM;
		}
		for(i=1;i<=n;i++){
			if(i==n)printf("%lld\n",sum[i]);
			else printf("%lld ",sum[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
