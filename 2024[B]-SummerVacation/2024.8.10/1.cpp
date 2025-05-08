#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1000000000000000009LL;
struct nod{
	int u,v,next;
};
nod a[600009];
int fir[300009],cnt,x,y,val[300009],T,i,j,n,f[300009][23],sum,ans,ANS;
int vis[300009];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs(int u){
	int i,j,k;
	bool ff=0;
	vis[u]=1;
	for(i=1;i<=20;i++){//ÔÚµÚiÂÖ±»É±ËÀ 
		f[u][i]=val[u]*i;
	}
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			ff=1;
			dfs(v);
			for(j=1;j<=20;j++){
				int mini=inf;
				for(k=1;k<=20;k++){
					if(j!=k)mini=min(mini,f[v][k]);
				}
				f[u][j]+=mini;
			}
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;sum=0;ANS=inf;
		for(i=1;i<=n;i++){
			scanf("%lld",&val[i]);
			fir[i]=0;vis[i]=0;
			sum+=val[i];
		}
		for(i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
		}
		dfs(1);
		for(i=1;i<=20;i++){
			ANS=min(ANS,f[1][i]);
		}
		printf("%lld\n",ANS);
		for(i=1;i<=n;i++){
			for(j=1;j<=20;j++){
				f[i][j]=0;
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
