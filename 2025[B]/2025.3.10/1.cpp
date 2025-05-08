#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,x,a[109],sum;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&x);sum=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		if(sum/n==x&&sum%n==0){
			printf("YES\n");
		}
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
