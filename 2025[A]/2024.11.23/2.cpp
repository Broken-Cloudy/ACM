#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int du,bh;
}t,k1,k2,rr1,rr2;
struct cmp{
	bool operator()(nod x,nod y){
		return x.du>y.du;
	}
};
int T,n,i,u,v,r,R[300009],w,du[300009],anss,r1,r2;
bool FF;
queue<int>q;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);FF=0;anss=0;R[0]=0;
		while(!q.empty())q.pop();
		for(i=1;i<=n;i++)du[i]=0;
		priority_queue<nod,vector<nod>,cmp>adj[n+3];
		vector<pair<int,int>>s;
		vector<set<int>>ss(n+3);
		vector<pair<int,int>>ans;
		for(i=1;i<n;i++){
			scanf("%lld%lld",&u,&v);
			s.push_back(make_pair(u,v));
			ss[u].insert(v);ss[v].insert(u);
			du[u]++;du[v]++;
		}
		for(i=1;i<=n;i++){
			if(du[i]%2==0)FF=1,R[++R[0]]=i;
			if(du[i]==1)q.push(i);
		}
		for(auto [x,y]:s){
			t.bh=y;t.du=du[y];
			adj[x].push(t);
			t.bh=x;t.du=du[x];
			adj[y].push(t);
		}
		if(FF==0&&(n-1)%2==1){
			printf("-1\n");
		}
		else{
			if((n-1)%2==0){//È«¶þ 
				while(!q.empty()){
					u=q.front();q.pop();
					if(du[u]==0)continue;
					while(adj[u].size()){
						t=adj[u].top();adj[u].pop();
						v=t.bh;
						if(du[v]==0||u==v)continue;
						else{
							while(adj[v].size()){
								t=adj[v].top();adj[v].pop();
								w=t.bh;
								if(du[w]==0||w==v||u==w)continue;
								else{
									anss++;
									ans.push_back(make_pair(u,w));
									du[v]-=2;du[u]--;du[w]--;
									if(du[u])for(auto tt:ss[u]){t.bh=u;t.du=du[u];adj[tt].push(t);}
									else for(auto tt:ss[u]){ss[tt].erase(u);}
									if(du[v])for(auto tt:ss[v]){t.bh=v;t.du=du[v];adj[tt].push(t);}
									else for(auto tt:ss[v]){ss[tt].erase(v);}
									if(du[w])for(auto tt:ss[w]){t.bh=w;t.du=du[w];adj[tt].push(t);}
									else for(auto tt:ss[w]){ss[tt].erase(w);}
									if(du[u]==1)q.push(u);
									if(du[v]==1)q.push(v);
									if(du[w]==1)q.push(w);
									break;
								}
							}
							break;
						}
					}
				}
			}
			else{
				for(i=1;i<=R[0];i++){
					r=R[i];
					k1=adj[r].top();adj[r].pop();
					k2=adj[r].top();adj[r].pop();
					u=k1.bh;v=k2.bh;
					if(du[u]%2==1&&du[u]>=3){
						rr1=adj[u].top();adj[u].pop();
						rr2=adj[u].top();adj[u].pop();
						r1=rr1.bh;r2=rr2.bh;
					}
					if(du[u]%2==1&&adj[r1].size()==1&&adj[r2].size()==1&&du[u]>=3||du[u]==1){
						w=r;adj[u].push(rr1);adj[u].push(rr2);
						while(w==r&&adj[v].size()){
							t=adj[v].top();adj[v].pop();
							w=t.bh;
						}
						du[r]-=2;du[v]-=2;
						du[w]--;du[u]--;
						if(du[r])for(auto tt:ss[r]){t.bh=r;t.du=du[r];adj[tt].push(t);}
						else for(auto tt:ss[r]){ss[tt].erase(r);}
						if(du[u])for(auto tt:ss[u]){t.bh=u;t.du=du[u];adj[tt].push(t);}
						else for(auto tt:ss[u]){ss[tt].erase(u);}
						if(du[v])for(auto tt:ss[v]){t.bh=v;t.du=du[v];adj[tt].push(t);}
						else for(auto tt:ss[v]){ss[tt].erase(v);}
						if(du[w])for(auto tt:ss[w]){t.bh=w;t.du=du[w];adj[tt].push(t);}
						else for(auto tt:ss[w]){ss[tt].erase(w);}
						anss++;
						ans.push_back(make_pair(w,u));
						if(du[u]==1)q.push(u);if(du[v]==1)q.push(v);
						if(du[w]==1)q.push(w);if(du[r]==1)q.push(r);
						break;
					}
					else{
						w=r;
						while(w==r&&adj[u].size()){
							t=adj[u].top();adj[u].pop();
							w=t.bh;
						}
						du[r]-=2;du[u]-=2;
						du[w]--;du[v]--;
						if(du[r])for(auto tt:ss[r]){t.bh=r;t.du=du[r];adj[tt].push(t);}
						else for(auto tt:ss[r]){ss[tt].erase(r);}
						if(du[u])for(auto tt:ss[u]){t.bh=u;t.du=du[u];adj[tt].push(t);}
						else for(auto tt:ss[u]){ss[tt].erase(u);}
						if(du[v])for(auto tt:ss[v]){t.bh=v;t.du=du[v];adj[tt].push(t);}
						else for(auto tt:ss[v]){ss[tt].erase(v);}
						if(du[w])for(auto tt:ss[w]){t.bh=w;t.du=du[w];adj[tt].push(t);}
						else for(auto tt:ss[w]){ss[tt].erase(w);}
						anss++;
						ans.push_back(make_pair(w,v));
						if(du[u]==1)q.push(u);if(du[v]==1)q.push(v);
						if(du[w]==1)q.push(w);if(du[r]==1)q.push(r);
						break;
					}
					adj[r].push(k1);
					adj[r].push(k2);
				}
				while(!q.empty()){
					u=q.front();q.pop();
					if(du[u]==0)continue;
					while(adj[u].size()){
						t=adj[u].top();adj[u].pop();
						v=t.bh;
						if(du[v]==0||u==v)continue;
						else{
							while(adj[v].size()){
								t=adj[v].top();adj[v].pop();
								w=t.bh;
								if(du[w]==0||w==v||u==w)continue;
								else{
									anss++;
									ans.push_back(make_pair(u,w));
									du[v]-=2;du[u]--;du[w]--;
									if(du[u])for(auto tt:ss[u]){t.bh=u;t.du=du[u];adj[tt].push(t);}
									else for(auto tt:ss[u]){ss[tt].erase(u);}
									if(du[v])for(auto tt:ss[v]){t.bh=v;t.du=du[v];adj[tt].push(t);}
									else for(auto tt:ss[v]){ss[tt].erase(v);}
									if(du[w])for(auto tt:ss[w]){t.bh=w;t.du=du[w];adj[tt].push(t);}
									else for(auto tt:ss[w]){ss[tt].erase(w);}
									if(du[u]==1)q.push(u);
									if(du[v]==1)q.push(v);
									if(du[w]==1)q.push(w);
									break;
								}
							}
							break;
						}
					}
				}
			}
			printf("%lld\n",anss);
			for(auto [x,y]:ans){
				printf("%lld %lld\n",x,y);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
