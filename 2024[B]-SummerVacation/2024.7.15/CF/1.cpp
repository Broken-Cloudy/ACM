#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&n,&k);
		ans=0;
		while(true){
			if(n<=1)break;
			n-=(k-1);
			ans++;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
