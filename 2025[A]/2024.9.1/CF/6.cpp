#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1000000007;
int T,i,j,n,a[200009],sum[200009],ans,r;
int x,y;
void exgcd(long long a,long long b){
	if(b==0){
		x=1;y=0;
		//gcd=a;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;y=t-(a/b)*y;
}
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		for(i=1;i<=n;i++){
			ans+=((sum[n]-sum[i])%inf)*a[i];
			ans%=inf;
		}
		r=n*(n-1)/2;r%=inf;
		exgcd(r,inf);
		ans=(((x%inf)*(ans%inf)%inf+inf)%inf);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
