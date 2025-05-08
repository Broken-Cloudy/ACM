#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
};
nod a[1009];
int n,i,x,y;
int fir[509],vis[509],cnt,ans,zhi,du[509];
void add(int x,int y){
	cnt++;
	a[cnt].u=x;a[cnt].v=y;a[cnt].next=fir[x];
	fir[x]=cnt;
}
void dfs(int u){//op==1 Irics op==0 Dora
	int i;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			du[u]++;du[v]++;
			dfs(v);
		}
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	if(n==2){
		cout<<"Bob"<<endl;
		return 0;
	}
	dfs(1);
	for(i=1;i<=n;i++){
		if(du[i]!=1)zhi++;
	}
	if((zhi-1)%2==0)cout<<"Bob"<<endl;
	else cout<<"Alice"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
