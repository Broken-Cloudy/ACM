#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a[200009],k,u,v,n,i,ans;
struct edg{
	int next,u,v;
};
int cnt,fir[200009],vis[200009];
edg edge[400009];
void add(int u,int v){
	edge[++cnt].next=fir[u];
	fir[u]=cnt;
	edge[cnt].u=u;
	edge[cnt].v=v;
}
void dfs(int u){
	int i;
	vis[u]=1;
	int r=1e9+7;
	for(i=fir[u];i;i=edge[i].next){
		int v=edge[i].v;
		if(vis[v]==0){
			dfs(v);
			r=min(r,a[v]);
		}
	}
	if(u==1&&r!=1000000007)a[u]+=r;
	else if(r!=1000000007){
		a[u]=min(r,(r+a[u])/2);
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=2;i<=n;i++){
			scanf("%lld",&k);
			add(i,k);add(k,i);
		}
		dfs(1);
		printf("%lld\n",a[1]);
		for(i=1;i<=n;i++)vis[i]=0,fir[i]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
