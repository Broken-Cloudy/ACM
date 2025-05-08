#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,a[200009],ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(n==1){
			ans=a[1];
		}
		else{
			ans=a[1]+a[2]-1;
			for(i=3;i<=n;i++){
				ans=ans+a[i]-1;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
