#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,n,u,v,len,cnt;
int fir[100009],vis[100009],dis[100009],ji,ou,ANS;
struct node{
	int bh,dis;
};
node d;
queue<node>q;
struct nod{
	int v,len,next;
};
nod a[800009];
void add(int u,int v,int len){
	cnt++;
	a[cnt].next=fir[u];
	a[cnt].v=v;
	a[cnt].len=len;
	fir[u]=cnt;
}
void dfs(int x,int ff){
	int i;
	if(vis[x]==1)return;
	else vis[x]=1;
	if(ff==0)ANS+=ji;
	else ANS+=ou;
	for(i=fir[x];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==1)continue;
		if(a[i].len%2==0){//Å¼ 
			if(ff==0)ou--;
			else ji--;
			dfs(v,ff);
		}
		else{//¼¦ 
			if(ff==0)ji--;
			else ou--;
			dfs(v,!ff);
		}
	}
}
signed main(){
	freopen("C.in","r",stdin);freopen("C.out","w",stdout);
	cin>>n;
	for(i=1;i<n;i++){
		scanf("%lld%lld%lld",&u,&v,&len);
		add(u,v,len);add(v,u,len);
	}
	d.bh=1;d.dis=0;
	dis[1]=0;vis[1]=1;
	q.push(d);
	while(!q.empty()){
		d=q.front();q.pop();
		u=d.bh;
		for(i=fir[u];i;i=a[i].next){
			v=a[i].v;
			if(vis[v]==1)continue;
			else{
				vis[v]=1;
				dis[v]=dis[u]+a[i].len;
				d.bh=v;d.dis=dis[v];
				q.push(d);
			}
		}
	}
	memset(vis,0,sizeof(vis));
	for(i=2;i<=n;i++){
		if(dis[i]%2==0)ou++;
		else ji++;
	}
	dfs(1,0);
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
