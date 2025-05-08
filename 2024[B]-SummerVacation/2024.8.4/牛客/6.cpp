#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,j,n,m,a[1009][1009],vis[1009][1009],ANS;
bool dfs(int x,int y){
	bool f=0;int t=a[x][y];
	if(x==n&&y==m){
		return 1;
	}
	vis[x][y]=1;
	if(a[x+1][y]>-1&&vis[x+1][y]==0){
		a[x][y]=0;
		if(dfs(x+1,y)==1){
			if(a[x][y+1]>-1&&a[x+1][y+1]>-1){
				vis[x][y+1]=1;vis[x+1][y+1]=1;
				ANS+=a[x][y+1];ANS+=a[x+1][y+1];
			}
			f=1;ANS+=t;
		}
		else a[x][y]=t;
	}
	if(a[x-1][y]>-1&&vis[x-1][y]==0){
		a[x][y]=0;
		if(dfs(x-1,y)==1){
			f=1;ANS+=t;
		}
		else a[x][y]=t;
	}
	if(a[x][y+1]>-1&&vis[x][y+1]==0){
		a[x][y]=0;
		if(dfs(x,y+1)==1){
			if(a[x+1][y]>-1&&a[x+1][y+1]>-1){
				vis[x+1][y]=1;vis[x+1][y+1]=1;
				ANS+=a[x+1][y];ANS+=a[x+1][y+1];
			}
			f=1;ANS+=t;
		}
		else a[x][y]=t;
	}
	if(a[x][y-1]>-1&&vis[x][y-1]==0){
		a[x][y]=0;
		if(dfs(x,y-1)==1){
			f=1;ANS+=t;
		}
		else a[x][y]=t;
	}
	vis[x][y]=0;
	return f;
}
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<=n+1;i++)a[i][0]=-1;for(i=0;i<=m+1;i++)a[n+1][i]=-1;
	for(i=0;i<=m+1;i++)a[0][i]=-1;for(i=0;i<=n+1;i++)a[i][m+1]=-1;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	dfs(1,1);
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
