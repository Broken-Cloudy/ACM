#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[200009];
struct node{
	int x,y;
}ans[100009];
int n,m,cnt,i,x,y,fir[100009],vis[100009],ff[100009],anss,p;
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
			if(ff[v]==1){
				anss++;
				ans[anss].x=u;ans[anss].y=v;
			}
			dfs(v);
		}
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	for(i=1;i<=m;i++){
		scanf("%lld",&x);
		ff[x]=1;p=x;
	}
	dfs(p);
	printf("%lld\n",anss);
	for(i=1;i<=anss;i++){
		printf("%lld %lld\n",ans[i].x,ans[i].y);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
