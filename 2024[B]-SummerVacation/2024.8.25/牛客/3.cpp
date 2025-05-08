#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n;
	if(n<=2)cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		cout<<n-1<<' '<<n<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
