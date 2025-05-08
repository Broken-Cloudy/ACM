#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int next,u,v,val;
}a[400009];
int n,m,i,T,fir[200009],x,y,V,cnt,pa[200009],vis[200009];
void add(int x,int y,int V){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;a[cnt].val=V;
	fir[x]=cnt;
}
void dfs_back(int start,int end){
	int p=pa[start];
	if(p==end){
		
		return;
	}
	else{
		
	}
}
void dfs(int u){
	int i;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(!vis[v]){
			pa[v]=u;
			dfs(v);
		}
		else if(vis[v]&&pa[u]!=v){//v是u的祖先，说明有环 
			dfs_back(u,v);//从u-->v back 
		}
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);cnt=0;
		for(i=1;i<=n;i++)fir[i]=0;
		for(i=1;i<=m;i++){
			scanf("%lld%lld%lld",&x,&y,&V);
			add(x,y,V);add(y,x,V);
		}
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
