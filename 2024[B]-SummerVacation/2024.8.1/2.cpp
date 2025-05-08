#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
};
map<int,map<int,int> >M;
nod a[500009];
int n,u,v,m,len,fir[1000009],i,j,cnt,vis[1000009],T,ans[500009];
int de[500009];
bool f=0;
void dfs(int x){
	int i;
	vis[x]=1;
	ans[++ans[0]]=x;
	for(i=1;i<=n;i++){
		if(vis[i]==0&&M[x][i]!=1){
			dfs(i);
		}
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		cnt=0;f=0;ans[0]=0;M.clear();
		for(i=0;i<=n;i++)fir[i]=0,vis[i]=0;
		for(i=1;i<=n;i++)de[i]=n-1;
		for(i=1;i<=m;i++){
			scanf("%lld%lld",&u,&v);
			de[u]--;de[v]--;
			M[u][v]=M[v][u]=1;
		}
		for(i=1;i<=n;i++){
			if(de[i]<(n-1)/2)f=1;
		}
		if(f==1){
			printf("-1\n");
			continue;
		}
		dfs(1);
		if(ans[0]==n){
			for(i=1;i<=ans[0];i++){
				if(i==ans[0])printf("%lld\n",ans[i]);
				else printf("%lld ",ans[i]);
			}
		}
		else printf("-1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
