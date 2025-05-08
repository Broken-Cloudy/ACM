#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,fir[5009],vis[5009],cnt,k,n;
struct nod{
	int u,v,next;
};
nod a[20009];
void add(int u,int v){
	cnt++;
	a[cnt].next=fir[u];
	a[cnt].u=u;a[cnt].v=v;
	fir[u]=cnt;
}
void dfs(int u){
	int i;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			
		}
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;
		for(i=1;i<=n;i++)fir[i]=0,vis[i]=0;
		for(i=2;i<=n;i++){
			scanf("%lld",&k);
			add(i,k);add(k,i);
		}
		dfs(1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
