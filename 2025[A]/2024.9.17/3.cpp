#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
};
nod a[200009];
int fir[100009],cnt,x,y,T,i,j,n,sum,ans,ANS;
int vis[100009],deep[100009];
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
			deep[v]=deep[u]+1;
			dfs(v);
		}
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n;
	for(i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1);
	int depth=0,node;
	for(i=1;i<=n;i++){
		if(deep[i]>=depth){
			depth=deep[i];
			node=i;
		}
	}
	for(i=1;i<=n;i++)deep[i]=vis[i]=0;
	dfs(node);
	int ans=0;
	for(i=1;i<=n;i++){
		ans=max(ans,deep[i]);
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
