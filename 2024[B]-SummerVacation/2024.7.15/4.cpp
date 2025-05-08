#include<bits/stdc++.h>
using namespace std;
int T,n,m,i,j,u,v;
int fir[100009],cnt,vis[100009],dis[100009],ans,k=1,f[100009];
struct nod{
	int u,v;
	int next;
};
nod a[400009];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
int abss(int x){
	return max(x,-x);
}
void dfs(int u,int deep,int start){
	if(f[start]==-1)return;
	for(int i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]>0){
			if(deep-vis[v]>=2){
				if(f[start]==1){
					f[start]=-1;
				}
				else if(f[start]==0){
					f[start]=1;
					ans=abss(deep-vis[v])+1;
				}
			}
		}
		else{
			vis[v]=deep+1;
			dfs(v,deep+1,start);
		}
	}
}
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		memset(fir,0,sizeof(fir));
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		k=0;cnt=0;ans=0;
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			add(u,v);add(v,u);
		}
		for(i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				dfs(i,1,i);
			}
		}
		for(i=1;i<=n;i++){
			if(f[i]==1)k++;
		}
		if(k==1){
			cout<<"Yes"<<' '<<ans<<endl;
		}
		else{
			cout<<"No"<<' '<<k<<endl;
		}
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
