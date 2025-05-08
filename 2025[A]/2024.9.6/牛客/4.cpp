#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,i,j,x,y,ans=-1,vis[2009][2009];
char c[2009][2009];
struct nod{
	int x,y;
	int ans,ff;
}t;
queue<nod>q;
bool check(int x,int y){
	if(x>=1&&x<=n&&y>=1&&y<=m)return 1;
	else return 0;
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n>>m>>x>>y;
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=m;j++){
			c[i][j]=getchar();
		}
	}
	t.x=x;t.y=y;t.ans=0;q.push(t);
	//ff==1我走 ff==2他走 
	while(!q.empty()){
		t=q.front();q.pop();
		int ff=t.ff;
		if(ff==0){
			if(check(t.x,t.y)&&check(x-(t.x-x),y-(t.y-y))){
				if(vis[t.x][t.y]==1)continue;
				else vis[t.x][t.y]=1;
				if(c[x-(t.x-x)][y-(t.y-y)]=='#'||c[x+(t.x-x)][y+(t.y-y)]=='#')continue;
				else if(c[x-(t.x-x)][y-(t.y-y)]=='.'&&c[x+(t.x-x)][y+(t.y-y)]=='.'){
					nod tt;
					tt.x=t.x+1;tt.y=t.y;tt.ans=t.ans+1;q.push(tt);
					tt.x=t.x;tt.y=t.y+1;tt.ans=t.ans+1;q.push(tt);
					tt.x=t.x-1;tt.y=t.y;tt.ans=t.ans+1;q.push(tt);
					tt.x=t.x;tt.y=t.y-1;tt.ans=t.ans+1;q.push(tt);
				}
				else if(c[x-(t.x-x)][y-(t.y-y)]=='@'&&c[x+(t.x-x)][y+(t.y-y)]=='@'){
					ans=t.ans;
					break;
				}
				else if(c[x-(t.x-x)][y-(t.y-y)]=='@'&&c[x+(t.x-x)][y+(t.y-y)]=='.'){
					ff=2;ans=t.ans*3;
				}
				else if(c[x-(t.x-x)][y-(t.y-y)]=='.'&&c[x+(t.x-x)][y+(t.y-y)]=='@'){
					ff=1;ans=t.ans*3;
				}
			}
		}
		else if(ff==1){
			if(check(x-(t.x-x),y-(t.y-y))){
				if(vis[t.x][t.y]==1)continue;
				else vis[t.x][t.y]=1;
				if(c[x-(t.x-x)][y-(t.y-y)]=='#')continue;
				else if(c[x-(t.x-x)][y-(t.y-y)]=='.'){
					nod tt;
					tt.x=t.x+1;tt.y=t.y;tt.ans=t.ans+1;q.push(tt);
					tt.x=t.x;tt.y=t.y+1;tt.ans=t.ans+1;q.push(tt);
					tt.x=t.x-1;tt.y=t.y;tt.ans=t.ans+1;q.push(tt);
					tt.x=t.x;tt.y=t.y-1;tt.ans=t.ans+1;q.push(tt);
				}
				else if(c[x-(t.x-x)][y-(t.y-y)]=='@'){
					ans=min(t.ans,ans);
					break;
				}
			}
		}
		else{
			if(check(t.x,t.y)){
				if(vis[t.x][t.y]==1)continue;
				else vis[t.x][t.y]=1;
				if(c[x+(t.x-x)][y+(t.y-y)]=='#')continue;
				else if(c[x+(t.x-x)][y+(t.y-y)]=='.'){
					nod tt;
					tt.x=t.x+1;tt.y=t.y;tt.ans=t.ans+1;q.push(tt);
					tt.x=t.x;tt.y=t.y+1;tt.ans=t.ans+1;q.push(tt);
					tt.x=t.x-1;tt.y=t.y;tt.ans=t.ans+1;q.push(tt);
					tt.x=t.x;tt.y=t.y-1;tt.ans=t.ans+1;q.push(tt);
				}
				else if(c[x+(t.x-x)][y+(t.y-y)]=='@'){
					ans=min(t.ans,ans);
					break;
				}
			}
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
