#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y,z,a,b,c,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>x>>y>>z>>a>>b>>c;
		ans=max(x*a,y*b);
		ans=max(ans,z*c);
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
