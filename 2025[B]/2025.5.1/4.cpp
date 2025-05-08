#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a,b,x,y,X,Y;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&a,&b);
		y=min(a,n-a);x=min(b,n-b);
		X=(x+1)/2;Y=y/2;
		if(X<=Y)printf("Alice\n");
		else printf("Bob\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
