#include<bits/stdc++.h>
using namespace std;
long long n,i,nchu[100010],u,v,fir[100010],cnt,f[100010][3];//f[][0]°× f[][1]ºì 
long long d=1,r,q[600010],vis[100010],ans;
const long long inf=1e9+7;
struct edg{
	int next,start,end;
};
edg edge[100010];
void add(long long u,long long v){
	edge[++cnt].next=fir[u];
	fir[u]=cnt;
	edge[cnt].end=v;
}
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n;
	for(i=1;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		add(u,v);add(v,u);
	}
	q[++r]=1;
	while(d<=r){
		u=q[d];vis[u]=1;
		for(i=fir[u];i;i=edge[i].next){
			v=edge[i].end;
			if(vis[v]==0){
				vis[v]=1;
				nchu[u]++;
				q[++r]=v;
			}
		}
		d++;
	}
	d=1;r=0;memset(q,0,sizeof(q));memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++)f[i][0]=1,f[i][1]=1;
	for(i=1;i<=n;i++){
		if(nchu[i]==0){
			q[++r]=i;
		}
	}
	//f[][0]°× f[][1]ºì 
	while(d<=r){
		u=q[d];vis[u]=1;
		for(i=fir[u];i;i=edge[i].next){
			v=edge[i].end;
			if(nchu[v]==0)continue;
			f[v][0]*=f[u][1];
			f[v][0]%=inf;
			f[v][1]*=(f[u][0]%inf+f[u][1]%inf);
			f[v][1]%=inf;
			nchu[v]--;
			if(nchu[v]==0){
				q[++r]=v;
			}
		}
		d++;
	}
	ans=f[1][0]+f[1][1];
	ans%=inf;
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
