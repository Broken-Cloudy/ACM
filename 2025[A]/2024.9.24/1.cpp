#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,i;
struct nod{
	int u,v,next;
}a[200009];
int cnt,fir[20009],x,y,c_point[20009],ans;
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
int dfn[20009],low[20009],timer,child;
void tarjan(int u,int ancestor){
	int i;
	dfn[u]=low[u]=++timer;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(dfn[v]==0){//未曾访问过 
			tarjan(v,ancestor);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]&&u!=ancestor){
				c_point[u]=1;//只要有一个点必须经过u，u就算作割点 
			}
			if(u==ancestor){//表示这次ancestor的一个儿子 
				child++;
			}
		}
		else low[u]=min(low[u],dfn[v]);//访问到已经搜过的点了 
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	for(i=1;i<=n;i++){
		child=0;
		if(dfn[i]==0)tarjan(i,i);
		if(child>=2)c_point[i]=1;
	}
	for(i=1;i<=n;i++)if(c_point[i])ans++;
	cout<<ans<<endl;
	for(i=1;i<=n;i++){
		if(c_point[i])printf("%lld ",i);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
