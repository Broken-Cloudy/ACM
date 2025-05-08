#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,x,ans;
signed main(){
	cin>>a>>b>>x;
	ans=x*a;
	ans=min(ans,(x/3)*b+(x-x/3*3)*a);
	ans=min(ans,b*((x+2)/3));
	cout<<ans<<endl;
	return 0;
}
