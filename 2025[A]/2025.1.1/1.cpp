#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[400009];
int T,i,j,n,cnt,ans,fir[200009],x,y,du[200009],b[200009],vis[200009];
map<int,map<int,int>>dp;
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs(int last,int u){
	int i;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			dfs(u,v);
			dp[u][v]+=dp[]
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;cnt=0;dp.clear();
		for(i=1;i<=n;i++)b[i]=vis[i]=du[i]=fir[i]=0;
		for(i=1;i<=n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
			du[x]++;du[y]++;
		}
		for(i=1;i<=n;i++){
			if(du[i]==1){
				b[i]=1;vis[i]=1;
				for(j=fir[i];j;j=a[j].next){
					b[a[j].v]=2;
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
