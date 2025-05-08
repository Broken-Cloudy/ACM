#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,i,j,x,y,vis[1009][1009],xx,yy;
char c[1009][1009];
set<int>s;
bool f=0;
void dfs(int x,int y,int deep){
	vis[x][y]=1;
	s.insert(x);s.insert(y+1000);
	if(deep==1)return;
	if(x+1<=n&&vis[x+1][y]==0&&c[x+1][y]!='#')dfs(x+1,y,deep);
	else if(deep==0&&c[x+1][y]=='#'&&x+1<=n&&vis[x+1][y]==0)dfs(x+1,y,deep+1);
	if(x-1>=1&&vis[x-1][y]==0&&c[x-1][y]!='#')dfs(x-1,y,deep);
	else if(deep==0&&c[x-1][y]=='#'&&x-1>=1&&vis[x-1][y]==0)dfs(x-1,y,deep+1);
	if(y+1<=m&&vis[x][y+1]==0&&c[x][y+1]!='#')dfs(x,y+1,deep);
	else if(deep==0&&c[x][y+1]=='#'&&y+1<=m&&vis[x][y+1]==0)dfs(x,y+1,deep+1);
	if(y-1>=1&&vis[x][y-1]==0&&c[x][y-1]!='#')dfs(x,y-1,deep);
	else if(deep==0&&c[x][y-1]=='#'&&y-1>=1&&vis[x][y-1]==0)dfs(x,y-1,deep+1);
}
void DFS(int x,int y){
	vis[x][y]=1;
	if(f==1)return;
	if(s.count(x)==1||s.count(y+1000)==1){
		f=1;return;
	}
	if(x+1<=n&&vis[x+1][y]==0&&c[x+1][y]!='#')DFS(x+1,y);
	if(x-1>=1&&vis[x-1][y]==0&&c[x-1][y]!='#')DFS(x-1,y);
	if(y+1<=m&&vis[x][y+1]==0&&c[x][y+1]!='#')DFS(x,y+1);
	if(y-1>=1&&vis[x][y-1]==0&&c[x][y-1]!='#')DFS(x,y-1);
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=m;j++){
			c[i][j]=getchar();
			if(c[i][j]=='E'){
				x=i;y=j;
			}
			else if(c[i][j]=='S'){
				xx=i;yy=j;
			}
		}
	}
	dfs(x,y,0);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)vis[i][j]=0;
	DFS(xx,yy);
	if(f==1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
