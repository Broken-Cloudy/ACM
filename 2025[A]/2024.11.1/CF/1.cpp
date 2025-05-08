#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,x,c1,c0;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;c1=c0=0;
		for(i=1;i<=2*n;i++){
			scanf("%lld",&x);
			if(x==1)c1++;
			else c0++;
		}
		if(c1>n)printf("%lld %lld\n",c1%2,2*n-c1);
		else printf("%lld %lld\n",c1%2,c1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
