#include<bits/stdc++.h>
#define int long long
#define inf 1000000009LL
using namespace std;
int n,m,f[49][49],i,j,u,v,ans,vis[49],dis[49];
queue<int>q;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)f[i][j]=inf;
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&u,&v);
		f[u][v]=f[v][u]=1;
	}
	for(i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(j=1;j<=n;j++)dis[j]=-inf;
		dis[i]=1;q.push(i);
		while(!q.empty()){
			int t=q.front();q.pop();
			if(vis[t]==1){
				continue;
			}
			else vis[t]=1;
			for(j=1;j<=n;j++){
				if(f[t][j]!=inf&&vis[j]==0){
					if(dis[j]==dis[t]){
						dis[j]=max(dis[j],dis[t]+1);
						q.push(j);
					}
				}
			}
		}
		for(j=1;j<=n;j++)ans=max(ans,dis[j]);
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
