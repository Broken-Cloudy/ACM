#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,st,en,x,y;
struct nod{
	int u,v,next;
}a[200009];
int cnt,fir[100009],vis[100009],ans[100009];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs(int u){
	int i;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			dfs(v);
		}
	}
	ans[++ans[0]]=u;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&st,&en);ans[0]=0;
		for(i=1;i<=n;i++)fir[i]=vis[i]=0;cnt=0;
		for(i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
		}
		dfs(en);
		for(i=1;i<=ans[0];i++){
			if(i==ans[0])printf("%lld\n",ans[i]);
			else printf("%lld ",ans[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
