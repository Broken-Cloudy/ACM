#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,q,a[200009],K,b[200009],f[200009],g[200009],sum,j,ans;
map<int,int>M;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	cin>>q;
	while(q--){
		scanf("%lld",&K);
		for(i=1;i<=n;i++)if(a[i]>K)b[++b[0]]=a[i];ans=b[0];
		for(i=b[0];i>=1;i--){
			f[b[i]]++;sum=0;
			for(j=1;j<=b[i];j++){
				sum+=f[j];
			}
			ans=min(ans,b[0]-sum);
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
