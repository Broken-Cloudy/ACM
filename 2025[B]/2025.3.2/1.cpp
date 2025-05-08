#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353LL;
struct nod{
	int u,v,next;
}a[600009];
int T,n,i,j,x,y,fir[300009],cnt,vis[300009],ANS,depth[300009];
int F[300009],f[300009],deep[300009];
queue<int>q;
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs(int u,int dep){
	int i;
	vis[u]=1;depth[dep]++;deep[u]=dep;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			dfs(v,dep+1);
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ANS=0;cnt=0;
		while(!q.empty())q.pop();
		for(i=1;i<=n;i++)vis[i]=fir[i]=f[i]=F[i]=depth[i]=0;
		for(i=2;i<=n;i++){
			scanf("%lld",&j);
			add(i,j);add(j,i);
		}
		dfs(1,1);
		for(i=1;i<=n;i++)vis[i]=0;
		q.push(1);f[1]=1;
		while(!q.empty()){
			x=q.front();q.pop();vis[x]=1;
			f[x]+=F[deep[x]];f[x]%=P;
			F[deep[x]+1]+=f[x];F[deep[x]+1]%=P;
			for(i=fir[x];i;i=a[i].next){
				y=a[i].v;
				if(vis[y]==0){
					if(deep[x]>1)f[y]-=f[x];
					f[y]%=P;
					q.push(y);
				}
			}
		}
		for(i=1;i<=n;i++){
			ANS+=(f[i]%P+P)%P;ANS%=P;
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
