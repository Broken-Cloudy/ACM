#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int en[1000010],next2[1000010],fir[500010],cnt;
int deep[500010],f[500010][20],father[500010]; 
int u,v,x,y,n,j,i,q,t,ans;
void add(int u,int v){
	cnt++;
	next2[cnt]=fir[u];
	fir[u]=cnt; 
	en[cnt]=v;
}
void dfs(int u,int depth){
	int t;
	deep[u]=depth;
	t=fir[u];
	while(t>0){
		if(en[t]!=father[u]){
			father[en[t]]=u;
			dfs(en[t],depth+1);
		}
		t=next2[t];
	}
}
int lca(int u,int v){
	int m,i;
	if(deep[u]<deep[v])swap(u,v);
	m=log2(deep[u]-deep[v]);
	for(i=m;i>=0;i--){
		if(deep[u]-(1<<i)>=deep[v])u=f[u][i];
	}
	if(u==v)return u;
	m=log2(deep[u]);
	for(i=m;i>=0;i--){
		if(f[u][i]==f[v][i])continue;
		else{
			u=f[u][i];
			v=f[v][i];
		}
	}
	return father[u];
}
int main(){
	int r;
	cin>>n>>q>>r;
	for(i=1;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(r,1);
	for(i=1;i<=n;i++)f[i][0]=father[i];
	for(j=1;(1<<j)<=n;j++){
		for(i=1;i<=n;i++){
			if(deep[i]>(1<<j))f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	for(i=1;i<=q;i++){
		scanf("%d%d",&u,&v);
		t=lca(u,v);
		printf("%d\n",t);
	}
	return 0;
}
