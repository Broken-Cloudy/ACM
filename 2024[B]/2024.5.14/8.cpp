#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a,b,acha,bcha,ha,hb;
signed main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	cin>>T;
	for(i=1;i<=T;i++){
		scanf("%lld%lld%lld",&n,&a,&b);
		acha=min(n-b,b);
		ha=(acha+1)/2;
		bcha=min(n-a,a);
		hb=bcha/2;
		if(ha==hb)printf("Alice\n");
		else if(ha>hb)printf("Bob\n");
		else if(ha<hb)printf("Alice\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
