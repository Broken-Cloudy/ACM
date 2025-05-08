#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
};
nod a[200009];
char c[200009];
int n,i,cnt,u,v,fir[100009],ans,vis[100009];
void add(int u,int v){
	cnt++;
	a[cnt].next=fir[u];
	a[cnt].u=u;a[cnt].v=v;
	fir[u]=cnt;
}
void dfs(int u){
	int i;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			if(c[u]!=c[v])ans++;
			dfs(v);
		}
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;getchar();
	for(i=1;i<=n;i++)c[i]=getchar();
	for(i=1;i<n;i++){
		scanf("%lld%lld",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(1);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
