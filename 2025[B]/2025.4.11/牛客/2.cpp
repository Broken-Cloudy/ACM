#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,a[100009],ton[100009],ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ton[a[i]]=1;
	}
	for(i=1;i<=n;i++){
		if(ton[i]==1)ans+=i;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
