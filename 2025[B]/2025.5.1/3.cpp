#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,i,j,pre[1000009],x[1000009],ans,l,r;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>m>>k;
	for(i=0;i<=m;i++){
		x[i]=(m-i);
		if(i>0)x[i]*=2;
	}
	for(i=m;i>=0;i--){
		pre[i]=pre[i+1]+x[i];
	}
	for(i=1;i<=n;i++){
		l=k-(n-i);
		l=max(l,0LL);r=min(m,k);
		ans+=(pre[l]-pre[r]);
		if(r==k&&r>0)ans+=x[r]/2;
		else ans+=x[r];
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
