#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,i,a[100009];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	if(a[n]-a[1]>=k){
		cout<<a[n]<<endl;
	}
	else{
		cout<<a[n-1]<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
