#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
bool f=0;
signed main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	if(n>=10&&n<=99){
		if((n%10)==(n/10))f=1;
	}
	if(f)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	//fclose(stdin);fclose(stdout);
	return 0;
}
