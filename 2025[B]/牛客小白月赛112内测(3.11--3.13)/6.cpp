#include<bits/stdc++.h>
using namespace std;
int n,m,a[509],i,j,X,y,x,f[10009],Pre[10009],bh[10009],vis[509];
int g[109],pre[109],b[109],ans1[509],ans2[509];
int F[10009],P[10009],B[10009];
void dfs1(int x){
	if(Pre[x]>0)dfs1(Pre[x]);
	vis[bh[x]]=1;
}
void dfs2(int x){
	if(Pre[x]>0)dfs2(Pre[x]);
	vis[bh[x]]=0;
}
void dfs3(int x){
	if(P[x]>0)dfs3(P[x]);
	vis[B[x]]=1;
}
void dfs4(int x){
	if(P[x]>0)dfs4(P[x]);
	vis[B[x]]=0;
}
void DFS1(int x){
	if(Pre[x]>0)DFS1(Pre[x]);
	ans1[++ans1[0]]=a[bh[x]];
}
void DFS2(int x){
	if(pre[x]>0)DFS2(pre[x]);
	ans2[++ans2[0]]=a[b[x]];
}
void DFS3(int x){
	if(P[x]>0)DFS3(P[x]);
	ans1[++ans1[0]]=a[B[x]];
}
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);f[0]=1;
	for(i=n;i>=1;i--){//500
		for(j=10000;j>=a[i];j--){//y=10000
			if(f[j]==0&&f[j-a[i]]==1){
				Pre[j]=j-a[i];bh[j]=i;
				f[j]=1;
			}
		}
	}
	F[0]=1;
	for(i=1;i<=n;i++){//500
		for(j=10000;j>=a[i];j--){//y=10000
			if(F[j-a[i]]==1){
				P[j]=j-a[i];B[j]=i;
				F[j]=1;
			}
		}
	}
	while(m--){//1000
		scanf("%d",&X);
		ans1[0]=ans2[0]=0;
		for(x=1;x*x<=X;x++){
			if(X%x==0){//15
				y=X/x;
				if(f[y]==1){
					dfs1(y);
					for(i=0;i<=x;i++)g[i]=pre[i]=b[i]=0;
					g[0]=1;
					for(i=1;i<=n;i++){
						if(vis[i]==1)continue;
						for(j=x;j>=a[i];j--){//100
							if(g[j]==0&&g[j-a[i]]==1){
								g[j]=1;pre[j]=j-a[i];b[j]=i;
							}
						}
						if(g[x]==1)break;
					}
					dfs2(y);
					if(g[x]==1){
						DFS1(y);DFS2(x);
						break;
					}
				}
			}
		}
		if(ans1[0]>0&&ans2[0]>0){
			printf("YES\n");
			printf("%d %d\n",ans1[0],ans2[0]);
			for(i=1;i<=ans1[0];i++){
				if(i==ans1[0])printf("%d\n",ans1[i]);
				else printf("%d ",ans1[i]);
			}
			for(i=1;i<=ans2[0];i++){
				if(i==ans2[0])printf("%d\n",ans2[i]);
				else printf("%d ",ans2[i]);
			}
		}
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
