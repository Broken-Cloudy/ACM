#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,i,n,m,x[109],y[109],C,xmax,ymax,X,Y;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=2;i++)printf("1 ");
		for(i=3;i<=n-1;i++)printf("%lld ",i-1);
		printf("1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
