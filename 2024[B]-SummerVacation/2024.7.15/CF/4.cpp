#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[1000009],dp[1000009][3];
int x,y,cnt,fir[1000009],i,vis[1000009],ans;
struct nod{
	int next;
	int u,v;
};
nod edg[4000009];
void add(int u,int v){
	cnt++;
	edg[cnt].next=fir[u];
	edg[cnt].u=u;edg[cnt].v=v;
	fir[u]=cnt;
}
void dfs(int u){
	int i;
	dp[u][0]=0;
	dp[u][1]=a[u];
	for(i=fir[u];i;i=edg[i].next){
		int v=edg[i].v;
		if(vis[v]==0){
			vis[v]=1;
			dfs(v);
			dp[u][0]+=max(dp[v][0],dp[v][1]);
			dp[u][1]+=dp[v][0];
		}
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		cnt=ans=0;
		for(i=0;i<=n;i++){
			a[i]=0;fir[i]=0;vis[i]=0;
			dp[i][0]=dp[i][1]=0;
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			ans+=a[i];
		}
		for(i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
		}
		vis[1]=1;
		dfs(1);
		ans+=(ans-max(dp[1][0],dp[1][1]));
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
