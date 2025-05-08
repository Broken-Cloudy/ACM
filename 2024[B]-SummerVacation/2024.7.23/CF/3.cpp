#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200009],i,j,t,ci,ans;
int now,nowci;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		now=a[1];nowci=0;ans=0;
		for(i=2;i<=n;i++){
			t=a[i];ci=0;
			if(t==1&&now!=1){
				ans=-1;
				break;
			}
			while(t<now){
				t=t*t;
				ci++;
			}
			ans+=(ci+nowci);
			now=t;
			if(now>=100000000LL){
				int ss=sqrt(now);
				if(ss*ss==now){
					now=ss;nowci++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
