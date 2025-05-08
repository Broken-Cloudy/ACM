#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Max_N=1e5+9;
int T,n,m,i,u,v,kong[Max_N];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		vector<set<int>>adj(n+3);
		for(i=1;i<=m;i++){
			scanf("%lld%lld",&u,&v);
			adj[u].insert(v);
			adj[v].insert(u);
		}
		vector<tuple<int,int,int>>ans;
		for(i=1;i<=n;i++){
			while(adj[i].size()>=2){
				u=*adj[i].begin();
				adj[i].erase(adj[i].begin());
				v=*adj[i].begin();
				adj[i].erase(adj[i].begin());
				adj[u].erase(i);adj[v].erase(i);
				ans.emplace_back(i,u,v);
				if(adj[u].count(v)){
					adj[u].erase(v);
					adj[v].erase(u);
				}
				else{
					adj[u].insert(v);
					adj[v].insert(u);
				}
			}
		}
		kong[0]=0;
		vector<pair<int,int>>P;
		for(i=1;i<=n;i++){
			if(adj[i].size()==0){
				kong[++kong[0]]=i;
			}
			else if(*adj[i].begin()>i){//确保只用一次 
				int rr=*adj[i].begin();
				P.emplace_back(i,*adj[i].begin());
			}
		}
		if(P.size()){//树 
			auto [x,y]=P.back();
			P.pop_back();
			for(i=1;i<=kong[0];i++){
				ans.emplace_back(x,y,kong[i]);
				y=kong[i];
			}
			while(!P.empty()){
				auto [u,v]=P.back();
				P.pop_back();
				ans.emplace_back(x,y,u);
				y=u;
			}
		}
		printf("%u\n",ans.size());
		for(auto [u,v,w]:ans){
			printf("%lld %lld %lld\n",u,v,w);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
