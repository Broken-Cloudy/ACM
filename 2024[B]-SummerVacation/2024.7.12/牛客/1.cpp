#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,a[100009],i;
bool f=0;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(x==a[i])f=1;
	} 
	if(f==0)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
