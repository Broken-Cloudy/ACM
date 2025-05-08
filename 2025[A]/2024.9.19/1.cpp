#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
int T,a,b,r,c,ans1,i,ans2,ans,d1,d2;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&a,&b,&r);
		c=a^b;ans1=0;ans2=0;
		for(i=61;i>=0;i--){
			if((c&(1LL<<i))>0&&ans1+(1LL<<i)<=r){
				d1=abs((a^ans1)-(b^ans1));
				d2=abs((a^(ans1+(1LL<<i)))-(b^(ans1+(1LL<<i))));
				if(d2<d1){
					ans1+=(1LL<<i);
				}
			}
			if((c&(1LL<<i))>0&&ans2+(1LL<<i)<=r&&(2LL<<i)<=abs(a-b)){
				d1=abs((a^ans2)-(b^ans2));
				d2=abs((a^(ans2+(1LL<<i)))-(b^(ans2+(1LL<<i))));
				if(d2<d1){
					ans2+=(1LL<<i);
				}
			}
		}
		ans=min(abs((a^ans1)-(b^ans1)),abs((a^ans2)-(b^ans2)));
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
