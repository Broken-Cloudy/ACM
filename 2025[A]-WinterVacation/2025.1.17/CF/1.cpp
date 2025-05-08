#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,i,n,m,x[109],y[109],C,xmax,ymax,X,Y;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);C=0;
		for(i=1;i<=n;i++){
			scanf("%lld%lld",&X,&Y);
			x[i]=x[i-1]+X;y[i]=y[i-1]+Y;
		}
		sort(x+1,x+1+n);sort(y+1,y+1+n);
		xmax=ymax=0;
		for(i=1;i<=n;i++){
			if(x[i]>=xmax){
				C+=m;
				xmax=x[i]+m;
			}
			else{
				C+=(x[i]+m-xmax);
				xmax=x[i]+m;
			}
		}
		for(i=1;i<=n;i++){
			if(y[i]>=ymax){
				C+=m;
				ymax=y[i]+m;
			}
			else{
				C+=(y[i]+m-ymax);
				ymax=y[i]+m;
			}
		}
		C*=2;
		printf("%lld\n",C);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
