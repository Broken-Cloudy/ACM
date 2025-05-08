#include<bits/stdc++.h>
using namespace std;
int i,n;
double k,ans=-1e18;
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;
		ans=max(ans,k);
	}
	cout<<ans<<endl;
	return 0;
}
