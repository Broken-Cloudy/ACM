#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,a[400009];
int prime[10000009],cnt,f[10000009],sum,SUM,ans;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	for(i=2;i<=10000000;i++){
		if(f[i]==0){
			prime[++cnt]=i;
			for(j=i;j<=10000000;j+=i){
				f[j]=i;
			}
		}
	}
	cin>>T;
	while(T--){
		scanf("%lld",&n);sum=SUM=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+1+n);ans=0;
		for(i=n,j=1;i>=1;i--,j++){
			sum+=a[i];
			SUM+=prime[j];
			if(sum<SUM){
				ans=i;
				break;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
