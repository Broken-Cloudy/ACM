#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9+7;
int n,k,a[200009],i,ans;
map<int,int>M1;
map<int,int>M2;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++){
		M1[a[i]]++;
		ans+=M2[a[i]-k]*M1[a[i]];ans%=inf;
		M2[a[i]]=max(M2[a[i]-k]*M1[a[i]],M1[a[i]]);
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
