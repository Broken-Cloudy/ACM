#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y,ANS,i,j,ans,f;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&x,&y);ANS=0;
		for(i=0;i<=34;i++){
			if(((1LL<<i)&x)&&((1LL<<i)&y)){
				f=0;ans=0;
				for(j=i-1;j>=0;j--){
					ans+=(1LL<<j);
					if((((1LL<<j)&x)&&((1LL<<j)&y)==0)||(((1LL<<j)&x)==0&&((1LL<<j)&y))){
						f=1;
						break;
					}
				}
				if(f==0)ans=(1LL<<i);
				ANS+=ans;x+=ans;y+=ans;
			}
		}
		for(i=0;i<=36;i++){
			if(((1LL<<i)&x)&&((1LL<<i)&y)){
				ANS=-1;
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
