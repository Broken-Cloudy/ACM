#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int next,u,v;
}a[200009];
int fir[100009];
int i,n,x,A,cnt,vis[100009];
int FF;
void dfs(int u){
	int i;
	if(FF==1)return;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(v==x)FF=1;
		if(vis[v]==0){
			dfs(v);
		}
	}
}
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>x;
	for(i=1;i<=n;i++){
		scanf("%lld",&A);
		add(A,i);
	}
	dfs(x);
	if(FF==1)printf("Yes\n");
	else printf("No\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
