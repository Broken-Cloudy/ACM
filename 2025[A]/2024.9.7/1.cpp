#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,x,y,ANS=1000000009,vis[2009][2009],ans[2009][2009];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char c[2009][2009];
bool check(int x,int y){
	if(x>=1&&x<=n&&y>=1&&y<=m)return 1;
	else return 0;
}
struct nod{
	int x,y;
	int ans;
}t;
queue<nod>q;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m>>x>>y;
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=m;j++){
			c[i][j]=getchar();
			if(c[i][j]=='@'){
				ans[i][j]=0;
				t.x=i;t.y=j;t.ans=0;q.push(t);
			}
			else ans[i][j]=1000000009;
		}
	}
	while(!q.empty()){
		t=q.front();q.pop();
		int xx=t.x,yy=t.y;
		if(check(xx,yy)){//±ß½ç 
			if(c[xx][yy]=='#')continue;//ÏÝÚå 
			if(vis[xx][yy]==1)continue;
			else vis[xx][yy]=1;
			nod tt;
			for(int o=0;o<=3;o++)tt.x=xx+dx[o],tt.y=yy+dy[o],tt.ans=t.ans+1,q.push(tt);
			ans[xx][yy]=min(ans[xx][yy],t.ans);
		}
	}
	memset(vis,0,sizeof(vis));
	t.x=x;t.y=y;t.ans=0;q.push(t);
	while(!q.empty()){
		t=q.front();q.pop();
		int xx=t.x,yy=t.y;
		int x_x=x-(t.x-x),y_y=y-(t.y-y);
		if(check(xx,yy)&&check(x_x,y_y)){
			if(vis[xx][yy]==1)continue;
			else vis[xx][yy]=1;
			if(c[x_x][y_y]=='#'||c[xx][yy]=='#')continue;
			if(c[xx][yy]=='.'){
				nod tt;
				for(int o=0;o<=3;o++)tt.x=xx+dx[o],tt.y=yy+dy[o],tt.ans=t.ans+1,q.push(tt);
			}
			if(c[xx][yy]=='@'){
				ANS=min(ANS,t.ans+ans[x_x][y_y]);
			}
		}
	}
	if(ANS==1000000009)cout<<"-1"<<endl;
	else cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
