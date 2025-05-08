#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,node[200009],dp1[200009],dp2[200009],B[200009],b[200009],ANS,q,vis[200009];
struct nod{
	int u,v,next;
}a[400009];
int cnt,fir[200009],x,y;
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs1(int u){
	int i;
	bool F=0;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			F=1;
			dfs1(v);
		}
	}
	if(F==0)q=u;
}
void dfs2(int u){
	int i;
	bool FF=0;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;B[u]++;
		if(vis[v]==0){
			dfs2(v);FF=1;b[u]++;
			int maxx=dp1[v];
			if(maxx>dp1[u]){
				dp2[u]=dp1[u];
				dp1[u]=maxx;
			}
			else if(maxx>dp2[u]){
				dp2[u]=maxx;
			}
		}
	}
	if(FF==1){
		dp1[u]+=(b[u]-1);
		dp2[u]+=(b[u]-1);	
	}
	else{
		dp1[u]=1;
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<n;i++){        
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
		}
		for(i=1;i<=n;i++){
			for(j=fir[i];j;j=a[j].next){
				node[i]++;
			}
		}
		for(i=1;i<=n;i++){
			if(node[i]==1){
				for(j=fir[i];j;j=a[j].next){
					int v=a[j].v;
					q=v;
				}
			}
		}
		dfs1(q);
		for(i=1;i<=n;i++)if(vis[i]==1)vis[i]=0;
		dfs2(q);
		for(i=1;i<=n;i++){
			if(b[i]>=2)ANS=max(ANS,dp1[i]+dp2[i]-2*b[i]+B[i]);
			else if(b[i]==1)ANS=max(ANS,dp1[i]-b[i]+B[i]);
			else ANS=max(ANS,1LL);
		}
		printf("%lld\n",ANS);
		for(i=1;i<=n;i++)fir[i]=node[i]=dp1[i]=dp2[i]=vis[i]=b[i]=B[i]=0;cnt=0;ANS=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
