#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,i,u,v;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		vector<set<int> >adj(n+3);
		for(i=1;i<=m;i++){
			scanf("%lld%lld",&u,&v);
			adj[u].insert(v);
			adj[v].insert(u);
		}
		vector<tuple<int,int,int> >ans;
		for(i=1;i<=n;i++){
			while(adj.size()>=2){
				
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
