#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,r1,r2,r3,r4,n,m;
double x[5],y[5];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		printf("? %lld %lld\n",1LL,1LL);fflush(stdout);
		scanf("%lld",&r1);r1+=2;
		printf("? %lld %lld\n",n,m);fflush(stdout);
		scanf("%lld",&r2);r2=n+m-r2;
		printf("? %lld %lld\n",1LL,m);fflush(stdout);
		scanf("%lld",&r3);r3-=(m-1);
		x[1]=(r1-r3)/2.0;y[1]=(r1+r3)/2.0;x[2]=(r2-r3)/2.0;y[2]=(r2+r3)/2.0;
		if(x[1]>=1&&x[1]<=m&&y[1]>=1&&y[1]<=n){
			printf("? %.0lf %.0lf\n",y[1],x[1]);fflush(stdout);
			scanf("%lld",&r4);
			if(r4==0)printf("! %.0lf %.0lf\n",y[1],x[1]);
			else printf("! %.0lf %.0lf\n",y[2],x[2]);
			fflush(stdout);
		}
		else{
			printf("! %.0lf %.0lf\n",y[2],x[2]);
			fflush(stdout);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
