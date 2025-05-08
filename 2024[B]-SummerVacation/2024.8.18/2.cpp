#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,a[100009],i,ans,ANS;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)ans+=a[i];
	ans/=k;
	ANS=min(ans,m);
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
