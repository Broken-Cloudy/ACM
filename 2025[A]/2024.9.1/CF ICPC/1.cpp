#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,y,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>x>>y;
	while(x<3){
		if(y==2||x==2){
			ans+=2;
		}
		else ans+=1;
		x++;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
