#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[400009];
int T,i,n,x,y,cnt;
int fir[200009],vis[200009],ans,dp[200009];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs(int u){
	int i,kk=0,rr=0;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		kk++;
	}
	if(kk==1)dp[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			if(dp[v]==-1){
				dfs(v);
			}
		}
	}
}
signed main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;ans=0;
		for(i=1;i<=n;i++){
			fir[i]=vis[i]=0;
			dp[i]=-1;
		}
		for(i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
		}
		dfs(1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
