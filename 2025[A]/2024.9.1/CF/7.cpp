#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[200009],i,GCD,t;
void gcd(long long a,long long b){
	if(b==0){
		GCD=a;
		return;
	}
	gcd(b,a%b);
}
signed main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(n==1){
			if(a[1]<k)printf("%lld\n",k);
			else printf("%lld\n",k-1);
			continue;
		}
		sort(a+1,a+1+n);GCD=a[1];
		for(i=2;i<=n;i++){
			gcd(GCD,a[i]);
		}
		t=-GCD;k--;
		for(i=1;i<=n;i++){
			t+=GCD;
			if(t<=k){
				k++;
			}
		}
		printf("%lld\n",k);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
