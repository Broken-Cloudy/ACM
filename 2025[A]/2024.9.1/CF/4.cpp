#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,p[200009],vis[200009],ans[200009];
char c[200009];
void dfs(int u){
	int i;
	vis[u]=1;
	if(vis[p[u]]==0)dfs(p[u]);
	if(c[u]=='0')ans[u]=ans[p[u]]+1;
	else ans[u]=ans[p[u]];
}
void DFS(int u){
	int i;
	vis[u]=1;
	if(vis[p[u]]==0)DFS(p[u]);
	ans[u]=max(ans[u],ans[p[u]]);
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)vis[i]=0,ans[i]=0;
		for(i=1;i<=n;i++)scanf("%lld",&p[i]);
		getchar();
		for(i=1;i<=n;i++){//0 is black,1 is white
			c[i]=getchar();
		}
		for(i=1;i<=n;i++){
			if(vis[i]==0)dfs(i);
		}
		for(i=1;i<=n;i++){
			vis[i]=0;
		}
		for(i=1;i<=n;i++){
			if(vis[i]==0)DFS(i);
		}
		for(i=1;i<=n;i++){
			if(i!=n)printf("%lld ",ans[i]);
			else printf("%lld\n",ans[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
