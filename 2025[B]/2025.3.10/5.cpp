#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n1,n2,i,k1,k2,m,ans,x,y;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	for(i=0;i<30;i+=2){
		n1+=(1LL<<i);
	}
	for(i=1;i<30;i+=2){
		n2+=(1LL<<i);
	}
	while(T--){
		printf("%lld\n",n1);fflush(stdout);
		scanf("%lld",&k1);
		printf("%lld\n",n2);fflush(stdout);
		scanf("%lld",&k2);
		x=k1-n1;
		y=k2-n2;
		scanf("%lld",&m);
		ans
		printf("%lld\n",ans);fflush(stdout);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
