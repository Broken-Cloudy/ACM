#include<bits/stdc++.h>
#define int long long
using namespace std;
int S,D;
int w[1000009],i,n,m,u,v,len,vis[1000009],dis[1000009],Pre[1000009];
int sum[1000009],we[1000009];//最短路径数 
struct node{
	int bh,dis;
};
struct cmp{
	bool operator()(node x,node y){
		return x.dis<y.dis;
	}
};
struct nod{
	int next,len,u,v;
};
nod a[1000009];
int fir[1000009],cnt;
priority_queue<node,vector<node>,cmp>q;
void add(int u,int v,int len){
	cnt++;
	a[cnt].next=fir[u];
	a[cnt].u=u;
	a[cnt].v=v;
	a[cnt].len=len;
	fir[u]=cnt;
}
void dfs(int x,int deep){
	if(Pre[x]==-1){
		cout<<x<<' ';
		return;
	}
	else{
		dfs(Pre[x],deep+1);
		if(deep==0)cout<<x<<endl;
		else cout<<x<<' ';
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m>>S>>D;
	for(i=0;i<n;i++){
		scanf("%lld",&w[i]);
	}
	for(i=0;i<m;i++){
		scanf("%lld%lld%lld",&u,&v,&len);
		add(u,v,len);add(v,u,len);
	}
	//初始化 
	memset(dis,0x3f,sizeof(dis));
	Pre[S]=-1;
	sum[S]=1;
	we[S]=w[S];
	dis[S]=0;
	node k;
	k.bh=S;k.dis=0;
	q.push(k);
	while(!q.empty()){
		node k=q.top();q.pop();
		int u=k.bh;
		if(vis[u]==0){
			vis[u]=1;
			for(i=fir[u];i;i=a[i].next){
				int v=a[i].v;
				//计数时小于和等于要分开 
				if(dis[u]+a[i].len<dis[v]){
					node addition;
					addition.bh=v;
					addition.dis=dis[u]+a[i].len;
					dis[v]=dis[u]+a[i].len;
					q.push(addition);
					//直接更新
					sum[v]=sum[u];
					Pre[v]=u;
					we[v]=we[u]+w[v]; 
				}
				else if(dis[u]+a[i].len==dis[v]){
					node addition;
					addition.bh=v;
					addition.dis=dis[u]+a[i].len;
					dis[v]=dis[u]+a[i].len;
					q.push(addition);
					//判断更新
					sum[v]+=sum[u];
					if(we[u]+w[v]>we[v]){
						Pre[v]=u;
						we[v]=we[u]+w[v];
					}
				}
			}
		}
	}
	cout<<sum[D]<<' '<<we[D]<<endl;
	dfs(D,0);
	fclose(stdin);fclose(stdout);
	return 0;
}
