#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x,i,ans;
bool f1,f2,f3;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&x);
		f1=f2=0;ans=0;f3=0;
		for(i=30;i>=0;i--){
			if(x&(1LL<<i)){
				if(f3==1){
					if(f1==0)ans+=(1LL<<i);
					f1=1;
				}
				else f3=1;
			}
			else{
				if(f3==1){
					if(f2==0)ans+=(1LL<<i);
					f2=1;
				}
			}
		}
		if(f1==1&&f2==1)printf("%lld\n",ans);
		else printf("-1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
