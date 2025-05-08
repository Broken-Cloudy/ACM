#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,l,r,x,y,a,b,ans,v,t;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld%lld%lld%lld",&l,&r,&x,&y,&a,&b);
		if(x>y){//R抓P,R一开始在x,可以移动a 
			if(b>=a){
				ans=(x-l+(a-1))/a;
			}
			else{
				v=a-b;
				t=(x-y+(v-1))/v;
				if(y-t*b<l){
					ans=(x-l+(a-1))/a;
				}
				else{
					ans=t;
				}
			}
		}
		else{
			if(b>=a){
				ans=(r-x+(a-1))/a;
			}
			else{
				v=a-b;
				t=(y-x+(v-1))/v;
				if(y+t*b>r){
					ans=(r-x+(a-1))/a;
				}
				else{
					ans=t;
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
