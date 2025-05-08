#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
};
int T,cnt,point[100009],fir[2][100009],n,m,i,x,y,vis[100009],t,ans;
int f[100009],q[100009],dp[100009];
nod a[2][200009];
void dfs1(int x){
	int i;
	vis[x]=1;
	for(i=fir[1][x];i;i=a[1][i].next){
		if(!vis[a[1][i].v])dfs1(a[1][i].v);
	}
	q[++t]=x;
}
void dfs2(int x,int y){
	int i;
	vis[x]=0;
	f[x]=y;//连通块从属 
	if(x!=y){
		point[y]+=point[x];//权值继承 
		point[x]=0;
	}
	for(i=fir[0][x];i;i=a[0][i].next){
		if(vis[a[0][i].v])dfs2(a[0][i].v,y);
	}
}
void add(int x,int y,int type){//type==0正图 type==1反图 
	cnt++;
	a[type][cnt].next=fir[type][x];
	a[type][cnt].u=x;a[type][cnt].v=y;
	fir[type][x]=cnt;
}
void build3(){
	int i;
	cnt=0;
	memset(fir,0,sizeof(fir));
	memset(a[1],0,sizeof(a[1]));//存在a[1][]里面 
	for(i=1;i<=2*m;i+=2){
		int u=a[0][i].u;
		int v=a[0][i].v;
		if(f[u]!=f[v]){//新图
			add(f[u],f[v],1);
		}
	}
}
struct node{
	int ru,chu,bh;
};
struct cmp{
	bool operator()(node x,node y){
		return x.ru>y.ru;
	}
};
node p[100009];
queue<node>que;
void dfs(int u){
	int i;
	vis[u]=1;
	for(i=fir[1][u];i;i=a[1][i].next){
		int v=a[1][i].v;
		p[u].chu++;p[v].ru++;//拓扑排序无需管是否访问 
		if(!vis[v]){
			dfs(v);
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%lld",&point[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y,0);
		add(y,x,1);
	}
	for(i=1;i<=n;i++)if(!vis[i])dfs1(i);
	for(i=n;i>=1;i--){
		if(vis[q[i]])dfs2(q[i],q[i]);
	}
	build3();
	for(i=1;i<=n;i++){
		if(!vis[i])dfs(i);
	}
	for(i=1;i<=n;i++){
		p[i].bh=i;dp[i]=point[i];
		if(p[i].chu!=0||p[i].ru!=0){
			if(p[i].ru==0)que.push(p[i]);
		}
	}
	while(!que.empty()){
		node t=que.front();que.pop();
		int u=t.bh;vis[u]=0;
		bool ff=0;
		for(i=fir[1][u];i;i=a[1][i].next){
			int v=a[1][i].v;
			if(vis[v]){
				ff=1;
				p[u].chu--;p[v].ru--;
				if(p[v].ru==0){
					que.push(p[v]);
				}
				dp[v]=max(dp[v],dp[u]+point[v]);
			}
		}
	}
	for(i=1;i<=n;i++)ans=max(ans,dp[i]);
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
