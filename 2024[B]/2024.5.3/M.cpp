#include<bits/stdc++.h>
using namespace std;
int i,n,u,v,len,cnt;
int fir[100009],vis[100009],A,B,pre[100009],lu[100009],cntlu;
int zhan[100009];
int Alice,Bob;
struct node{
	int bh,dis;
};
node d;
queue<node>q;
struct nod{
	int v,next;
};
nod a[800009];
void add(int u,int v){
	cnt++;
	a[cnt].next=fir[u];
	a[cnt].v=v;
	fir[u]=cnt;
}
void dfs(int x){
	int i;
	if(vis[x]==1)return;
	else vis[x]=1;
	for(i=fir[x];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==1)continue;
		else{
			pre[v]=x;
			dfs(v);
		}
	}
}
void dfss(int x){
	int i;
	if(vis[x]==1)return;
	else vis[x]=1;
	for(i=fir[x];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==1||zhan[v]==2)continue;
		else{
			zhan[v]=1;
			dfss(v);
		}
	}
}
void dfsss(int x){
	int i;
	if(vis[x]==1)return;
	else vis[x]=1;
	for(i=fir[x];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==1||zhan[v]==1)continue;
		else{
			zhan[v]=2;
			dfsss(v);
		}
	}
}
void find(int x){
	if(x==0)return;
	lu[++cntlu]=x;
	find(pre[x]);
}
int main(){
	freopen("M.in","r",stdin);freopen("M.out","w",stdout);
	cin>>n>>A>>B;
	for(i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(B);
	find(A);
	for(i=1;i<=cntlu;i++){
		if(i<=(cntlu+1)/2)zhan[lu[i]]=1;//alice占领 
		else zhan[lu[i]]=2;//bob占领 
	}
	memset(vis,0,sizeof(vis));
	dfss(A);//alice
	memset(vis,0,sizeof(vis));
	dfsss(B);//bob
	for(i=1;i<=n;i++){
		if(zhan[i]==1)Alice++;
		else Bob++;
	}
	if(Alice>=Bob)cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
