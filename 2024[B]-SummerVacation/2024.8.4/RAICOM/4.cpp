#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,S,T,i,xx,yy,lenlen,vis[5009],dis[5009];
int pre[5009],prere[5009],re[5009],ans,anss;
struct nod{
	int u,v,len,next;
};
struct dd{
	int dis,bh;
};
nod a[200009];
struct cmp{
	bool operator()(dd x,dd y){
		return x.dis>y.dis;
	}
};
priority_queue<dd,vector<dd>,cmp>q;
int fir[5009],cnt;
void add(int x,int y,int len){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;a[cnt].len=len;
	fir[x]=cnt;
}
void dfs(int x){
	if(x==0)return;
	dfs(pre[x]);
	anss++;
	if(x!=T&&x!=S)ans=max(ans,re[x]);
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n>>m>>S>>T;
	for(i=1;i<=n;i++)scanf("%lld",&re[i]);
	for(i=1;i<=n;i++)dis[i]=1000000009,prere[i]=1000000009;
	dis[S]=0;prere[S]=0;
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&xx,&yy,&lenlen);
		add(xx,yy,lenlen);add(yy,xx,lenlen);
	}
	dd t;t.bh=S;t.dis=0;q.push(t);
	while(!q.empty()){
		dd r=q.top();q.pop();
		int u=r.bh;
		if(vis[u]==1)continue;
		vis[u]=1;
		for(i=fir[u];i;i=a[i].next){
			int v=a[i].v;
			if(vis[v]==0){
				if(dis[u]+a[i].len<dis[v]){
					dis[v]=dis[u]+a[i].len;
					dd ss;ss.bh=v;ss.dis=dis[v];
					q.push(ss);
					pre[v]=u;prere[v]=max(re[v],prere[u]);
				}
				else if(dis[u]+a[i].len==dis[v]){
					dd ss;ss.bh=v;ss.dis=dis[v];
					q.push(ss);
					if(max(re[v],prere[u])<prere[v]){
						pre[v]=u;
						prere[v]=max(re[v],prere[u]);
					}
				}
			}
		}
	}
	dfs(T);
	if(dis[T]==1000000009)cout<<"Impossible"<<endl;
	else cout<<anss<<' '<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
