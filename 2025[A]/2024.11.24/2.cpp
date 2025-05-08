#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q,i,j,k,a[9][9],b[9][9][9],ans[9][9];
char c;
bool f[9],FF;
void dfs(int i,int now,int maxx){
	if(FF==1)return;
	int x,y,z,j,k;
	if(now==maxx){
		for(x=1;x<=n;x++){
			for(y=1;y<=m;y++)ans[x][y]=a[x][y];
		}
		for(j=1;j<=q;j++){
			if(f[j]==1){
				for(x=1;x<=n;x++){
					for(y=1;y<=m;y++){
						if(b[j][x][y]==1)ans[x][y]=2;
					}
				}
			}
		}
		bool fff=0;
		for(x=1;x<=n;x++){
			if(fff==1)break;
			for(y=1;y<=m;y++){
				if(ans[x][y]==0&&a[x][y]==0){
					fff=1;break;
				}
				if(ans[x][y]==2&&a[x][y]==1){
					fff=1;break;
				}
			}
		}
		if(fff==0){
			FF=1;
			cout<<maxx<<endl;
			for(x=1;x<=q;x++){
				if(f[x]==1)cout<<x<<' ';
			}
		}
	}
	if(i>q)return;
	f[i]=1;
	dfs(i+1,now+1,maxx);
	f[i]=0;
	dfs(i+1,now,maxx);
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m>>q;
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=m;j++){
			c=getchar();
			a[i][j]=c-'0';
		}
	}
	for(k=1;k<=q;k++){
		for(i=1;i<=n;i++){
			getchar();
			for(j=1;j<=m;j++){
				c=getchar();
				b[k][i][j]=c-'0';
			}
		}
	}
	for(i=0;i<=q;i++){
		if(FF==1)break;
		dfs(1,0,i);
	}
	if(FF==0)cout<<-1<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
