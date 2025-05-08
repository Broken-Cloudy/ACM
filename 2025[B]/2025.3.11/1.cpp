#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n1,n2,i,k1,k2,m,x,y,t,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	for(i=0;i<30;i+=2)n1+=(1LL<<i);
	for(i=1;i<30;i+=2)n2+=(1LL<<i);
	cin>>T;
	while(T--){
		printf("%lld\n",n1);fflush(stdout);
		scanf("%lld",&k1);
		printf("%lld\n",n2);fflush(stdout);
		scanf("%lld",&k2);
		printf("!\n");fflush(stdout);
		scanf("%lld",&m);
		k1-=2*n1;k2-=2*n2;
		x=y=0;
		for(i=29;i>=1;i-=2){//n1
			t=k1/(1LL<<i);
			if(t==2){
				x+=(1LL<<i);
				y+=(1LL<<i);
			}
			else if(t==1)x+=(1LL<<i);
			k1%=(1LL<<i);
		}
		for(i=28;i>=0;i-=2){//n1
			t=k2/(1LL<<i);
			if(t==2){
				x+=(1LL<<i);
				y+=(1LL<<i);
			}
			else if(t==1)x+=(1LL<<i);
			k2%=(1LL<<i);
		}
		ans=(m|x)+(m|y);
		printf("%lld\n",ans);fflush(stdout);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
