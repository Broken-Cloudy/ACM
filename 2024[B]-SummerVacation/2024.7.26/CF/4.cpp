#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,sum,x,n,ans;
int a,b,c;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&n,&x);
		ans=0;
		for(a=1;a<=x;a++){
			for(b=1;b<=x-a;b++){
				if(a*b>=n)break;
				c=min(x-a-b,(n-a*b)/(a+b));
				ans+=c;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
