#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,vis[1009][1009],ans[1009][1009];
char c[1009][1009],ch;
bool f;
void solve(int x,int y){
	int i,j;
	for(i=x-1;i<=x+1;i++){
		for(j=y-1;j<=y+1;j++){
			if(c[i][j]=='.'&&ans[i][j]!=-1){
				ans[i][j]=1;
			}
		}
	}
}
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=m;j++){
			c[i][j]=getchar();
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(c[i][j]=='m'){
				vis[i][j]=1;
				vis[i+1][j]=1;vis[i][j+1]=1;vis[i+1][j+1]=1;
				vis[i-1][j]=1;vis[i][j-1]=1;vis[i-1][j-1]=1;
				vis[i-1][j+1]=1;vis[i+1][j-1]=1;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(c[i][j]=='c'){
				ans[i][j]=-1;
				ans[i+1][j]=-1;ans[i][j+1]=-1;ans[i+1][j+1]=-1;
				ans[i-1][j]=-1;ans[i][j-1]=-1;ans[i-1][j-1]=-1;
				ans[i+1][j-1]=-1;ans[i-1][j+1]=-1;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(c[i][j]=='w'&&vis[i][j]==0){
				solve(i,j);
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(ans[i][j]==1){
				f=1;
				printf("%d %d\n",i,j);
			}
		}
	}
	if(f==0)cout<<"Too cold!"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
