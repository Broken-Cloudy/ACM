#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[300009];
queue<int>q;
int x,y,i,j,T,n,fir[150009],cnt,vis[150009],dis[150009],maxx,p,bh,pre[150009];
struct node{
	int x,y,val;
}b[150009];
int bcnt;
bool cmp(node x,node y){
	if(x.val==y.val)return max(x.x,x.y)>max(y.x,y.y);
	else return x.val>y.val;
}
void add(int x,int y){
	cnt++;
	a[cnt].u=x;a[cnt].v=y;
	a[cnt].next=fir[x];
	fir[x]=cnt;
}
void dfs1(int u){
	int i;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			dis[v]=dis[u]+1;pre[v]=u;
			if(dis[v]>maxx){maxx=dis[v];bh=v;}
			else if(dis[v]==maxx&&v>bh)bh=v;
			dfs1(v);
		}
	}
}
void dfs2(int u){
	int i;
	vis[u]=0;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==1){
			dis[v]=dis[u]+1;pre[v]=u;
			if(dis[v]>maxx){maxx=dis[v];bh=v;}
			else if(dis[v]==maxx&&v>bh)bh=v;
			dfs2(v);
		}
	}
}
signed main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;q.push(1);bcnt=0;
		for(i=1;i<=n;i++)fir[i]=vis[i]=dis[i]=0;
		for(i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
		}
		while(!q.empty()){
			int t=q.front();q.pop();
			dis[t]=1;maxx=0;bh=0;dfs1(t);
			int d=bh;
			if(bh==0){
				vis[t]=2;
				bcnt++;
				b[bcnt].x=t;b[bcnt].y=t;b[bcnt].val=1;
				continue;
			}
			dis[d]=1;maxx=0;bh=0;dfs2(d);
			x=bh;p=1;vis[d]=2;
			while(x!=d){
				vis[x]=2;
				for(i=fir[x];i;i=a[i].next){
					y=a[i].v;
					if(vis[y]==0&&y!=pre[x]){
						q.push(y);
					}
				}
				x=pre[x];
			}
			bcnt++;
			b[bcnt].x=d;b[bcnt].y=bh;b[bcnt].val=dis[bh];
		}
		sort(b+1,b+1+bcnt,cmp);
		for(i=1;i<=bcnt;i++)printf("%lld %lld %lld\n",b[i].val,max(b[i].x,b[i].y),min(b[i].x,b[i].y));
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
