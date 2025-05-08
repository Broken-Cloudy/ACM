#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,a[100009],i,ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>x;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++){
		if(x==0)continue;
		else{
			if(x>0)x-=a[i];
			else x+=a[i];
			ans+=a[i];
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
