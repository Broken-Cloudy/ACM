#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,l,r,i,k,j,x,y,kk,ans;
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld%lld",&l,&r,&i,&k);ans=0;
		for(i=1;i<=62;i++){
			//从第x个到第y个 
			x=(l+(1LL<<i)-1)/(1LL<<i);
			y=r/(1LL<<i);
			kk=(y-x)*((1LL<<(i-1LL))-1);
			if(kk%2==1)ans+=(1LL<<i);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
