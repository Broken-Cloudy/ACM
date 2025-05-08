#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int factorial(int n){
	int i,ans=1;
	for(i=1;i<=n;i++){
		ans*=i;
	}
	return ans;
}
signed main(){
	cin>>n;
	cout<<factorial(n)<<endl;
	return 0;
}
