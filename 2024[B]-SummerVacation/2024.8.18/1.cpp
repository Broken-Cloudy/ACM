#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>a>>b>>c;
	if(a+b>c){
		cout<<"NO"<<endl;
	}
	else cout<<"YES"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
