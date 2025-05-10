#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
};
int T,cnt,fir[2][100009],n,m,i,x,y,vis[100009],t,ans;
int f[100009],q[100009],pcnt[100009];
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
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y,0);
		add(y,x,1);
	}
	for(i=1;i<=n;i++)if(!vis[i])dfs1(i);
	for(i=n;i>=1;i--){
		if(vis[q[i]])dfs2(q[i],q[i]);
	}
	for(i=1;i<=n;i++)pcnt[f[i]]++;
	for(i=1;i<=n;i++)if(pcnt[i]>=2)ans++;
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
