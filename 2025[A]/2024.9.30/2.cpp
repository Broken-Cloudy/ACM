#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,q,i,a,b[100009],d,ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&q);
		for(i=1;i<=m;i++)scanf("%lld",&b[i]);
		sort(b+1,b+1+m);
		while(q--){
			scanf("%lld",&a);
			d=lower_bound(b+1,b+1+m,a)-b;
			if(d==1){
				ans=b[1]-1;
			}
			else if(d==m+1){
				ans=n-b[m];
			}
			else{
				ans=(b[d]-b[d-1])/2;
			}
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
