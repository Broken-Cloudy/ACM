#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,xc,yc,k,f,i,x,y,X,Y;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;f=1;
	while(T--){
		scanf("%lld%lld%lld",&xc,&yc,&k);
		X=xc*k;Y=yc*k;
		for(i=10000;i<9999+k;i++){
			x=i;y=i;
			x*=f;y*=f;
			printf("%lld %lld\n",x,y);
			X-=x;Y-=y;
			f=-f;
		}
		printf("%lld %lld\n",X,Y);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
