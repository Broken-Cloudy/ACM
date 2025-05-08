#include<bits/stdc++.h>
#define int long long
using namespace std;
const double inf=1e9+7;
struct nod{
	int u,v,next;
};
nod a[1000009];
int n,m,k,i,u,v,cuo;
bool f,vis[100009],vv[100009];
int fir[100009],cnt,p,b[100009];
double r[100009],w[100009],W;
int ff[100009];
void add(int u,int v){
	cnt++;
	a[cnt].next=fir[u];
	a[cnt].u=u;
	a[cnt].v=v;
	fir[u]=cnt;
}
void dfs(int u){
	int i;
	if(vis[u]==1){
		return;
	}
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v; 
		if(w[v]==inf){
			w[v]=-(r[u]*w[u])/r[v];
			dfs(v);
		}
		else{
			if(w[v]!=-(r[u]*w[u])/r[v]){
				f=1;//错误 
			}
			else{
				dfs(v);//无 
			}
		}
	}
}
void dfs3(int u){
	int i;
	if(vv[u]==1){
		return;
	}
	vv[u]=1;
	w[u]=0;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vv[v]==0)dfs3(v);
	}
}
void dfs2(int u){
	int i;
	if(vis[u]==1){
		return;
	}
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		if(cuo==1)return;
		int v=a[i].v; 
		if(ff[u]==0){
			ff[u]=1;
		}
		if(ff[v]==0){
			ff[v]=-ff[u];
			dfs2(v);
		}
		else{
			if(ff[v]==ff[u]){
				cuo=1;//错误 
				return;
			}
			else{
				dfs2(v);//正确 
			}
		}
	}
}
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		w[i]=inf;
	}
	for(i=1;i<=n;i++){
		scanf("%lf",&r[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&u,&v);
		if(u==v)continue;
		add(u,v);add(v,u);
	}
	for(i=1;i<=k;i++){
		scanf("%lld%lf",&p,&W);
		b[++b[0]]=p;
		w[p]=W;
	}
	for(i=1;i<=b[0];i++){
		dfs(b[i]);
	}
	if(f==1){
		printf("It is not steampunk!");
	}
	else{
		bool ff2=0;
		for(i=1;i<=n;i++){
			if(w[i]==inf){
				ff2=1;//无穷解
				break; 
			}
		}
		if(ff2==1){
			memset(vis,0,sizeof(vis));
			for(i=1;i<=n;i++){
				cuo=0;
				if(w[i]==inf){
					memset(vis,0,sizeof(vis));
					dfs2(i);
				}
				if(cuo==1){
					memset(vv,0,sizeof(vv));
					dfs3(i);
				}
			}
			bool ff2=0;
			for(i=1;i<=n;i++){
				if(w[i]==inf){
					ff2=1;//无穷解
					break; 
				}
			}
			if(ff2==1)printf("oo");
			else{
				printf("Steampunk!\n");
				for(i=1;i<=n;i++){
					if(w[i]==-0)w[i]=0;
					if(i==n)printf("%.4lf",w[i]);
					else printf("%.4lf ",w[i]);
				}
			}
		}
		else{
			printf("Steampunk!\n");
			for(i=1;i<=n;i++){
				if(w[i]==-0)w[i]=0;
				if(i==n)printf("%.4lf",w[i]);
				else printf("%.4lf ",w[i]);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
