#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1000000009LL;
int T,m1,m2,n,s1,s2,i,j,x,y,ans[1009],ANS,u,v;
int a[1009][1009],b[1009][1009],f[1009][1009],vis[1009][1009];
struct nod{int x,y;int dis;}t;
struct cmp{
	bool operator()(nod x,nod y){
		return x.dis>y.dis;
	}
};
priority_queue<nod,vector<nod>,cmp>q;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&s1,&s2);
		for(i=1;i<=n;i++)a[i][0]=b[i][0]=ans[i]=0;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)f[i][j]=INF,vis[i][j]=0;
		scanf("%lld",&m1);
		for(i=1;i<=m1;i++){
			scanf("%lld%lld",&x,&y);vis[x][y]=vis[y][x]=1;
			a[x][++a[x][0]]=y;a[y][++a[y][0]]=x;
		}
		scanf("%lld",&m2);
		for(i=1;i<=m2;i++){
			scanf("%lld%lld",&x,&y);
			b[x][++b[x][0]]=y;b[y][++b[y][0]]=x;
			if(vis[x][y]==1)ans[x]=ans[y]=1;
		}
		while(!q.empty())q.pop();
		f[s1][s2]=0;t.x=s1;t.y=s2;t.dis=f[s1][s2];q.push(t);
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)vis[i][j]=0;
		while(!q.empty()){
			t=q.top();q.pop();
			x=t.x;y=t.y;
			if(vis[x][y]==1)continue;
			else vis[x][y]=1;
			for(i=1;i<=a[x][0];i++){
				for(j=1;j<=b[y][0];j++){
					u=a[x][i];v=b[y][j];
					if(f[x][y]+abs(u-v)<f[u][v]){
						f[u][v]=f[x][y]+abs(u-v);
						t.x=u;t.y=v;t.dis=f[u][v];
						q.push(t);
					}
				}
			}
		}
		ANS=INF;
		for(i=1;i<=n;i++)if(ans[i]==1)ANS=min(ANS,f[i][i]);
		if(ANS==INF)ANS=-1;
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
