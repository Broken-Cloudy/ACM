#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[300009];
int x,y,i,j,T,n,fir[150009],cnt,vis[150009],dis[150009],maxx,p,an[150009],anfa[150009];
struct node{
	int x,y,val;
}b[450009];
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
			dis[v]=dis[u]+1;
			dfs1(v);
			maxx=max(maxx,dis[v]);
		}
	}
}
void dfs2(int u){
	int i,k=0;
	vis[u]=0;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==1){
			k++;
		}
	}
	if(k==0){
		an[u]=u;
		anfa[u]=dis[u];
		return;
	}
	else if(k==1){
		for(i=fir[u];i;i=a[i].next){
			int v=a[i].v;
			if(vis[v]==1){
				dis[v]=dis[u]+1;
				dfs2(v);
				an[u]=an[v];anfa[u]=anfa[v];
			}
		}
	}
	else{
		node now,bb;
		now.x=-1;
		for(i=fir[u];i;i=a[i].next){
			int v=a[i].v;
			if(vis[v]==1){
				dis[v]=dis[u]+1;
				dfs2(v);
				bb.val=anfa[v]-dis[u];bb.x=v;bb.y=an[v];
				if(anfa[v]>anfa[u]){
					if(now.x!=-1)b[++bcnt]=now;
					now=bb;
					anfa[u]=anfa[v];
					an[u]=an[v];
				}
				else if(anfa[v]==anfa[u]&&an[v]>an[u]){
					if(now.x!=-1)b[++bcnt]=now;
					now=bb;
					an[u]=an[v];
				}
				else{
					bcnt++;
					b[bcnt]=bb;
				}
			}
		}
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;
		for(i=1;i<=n;i++)fir[i]=vis[i]=dis[i]=0;
		for(i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
		}
		maxx=0;dfs1(1);p=1;
		for(i=n;i>1;i--){
			if(dis[i]==maxx){
				p=i;
				break;
			}
		}
		for(i=1;i<=n;i++)dis[i]=anfa[i]=an[i]=0;
		bcnt=0;dis[p]=1;dfs2(p);bcnt++;
		b[bcnt].x=p;b[bcnt].y=an[p];b[bcnt].val=anfa[p];
		sort(b+1,b+1+bcnt,cmp);
		for(i=1;i<=bcnt;i++){
			printf("%lld %lld %lld\n",b[i].val,max(b[i].x,b[i].y),min(b[i].x,b[i].y));
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
