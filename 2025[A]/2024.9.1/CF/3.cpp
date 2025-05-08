#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,l,r,ANS;
double ans;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&l,&r);
		ans=r-l;
		ans=sqrt(2*ans+0.25)-0.5;
		ans=floor(ans);
		ans+=1;
		printf("%.0lf\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
