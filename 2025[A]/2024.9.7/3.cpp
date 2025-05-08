#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
};
nod a[400009];
set<int>s;
int n,m,x,y,i,j,ans,T,du[200009],vis[200009],X[200009],Y[200009];
int fir[200009],cnt;//2是新图
map<int,map<int,int> >Map;
void add(int x,int y){
	cnt++;Map[x][y]=cnt;
	a[cnt].next=fir[x];a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
int f[200009];
int find(int x){
	if(f[x]==x)return x;
	else{
		f[x]=find(f[x]);
		return f[x];
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);cnt=0;
		for(i=1;i<=n;i++)fir[i]=0,du[i]=0;
		for(i=1;i<=m;i++){
			scanf("%lld%lld",&X[i],&Y[i]);
			du[X[i]]++;du[Y[i]]++;f[i]=i;//并查集
		}
		for(i=1;i<=m;i++){//建立新图 
			if(du[X[i]]==du[Y[i]])add(min(X[i],Y[i]),max(X[i],Y[i]));
			else add((du[X[i]]<du[Y[i]]?X[i]:Y[i]),(du[X[i]]<du[Y[i]]?Y[i]:X[i]));
		}
		for(int u=1;u<=n;u++){
			for(i=fir[u];i;i=a[i].next){
				int v=a[i].v;
				vis[v]=i;
			}
			for(i=fir[u];i;i=a[i].next){
				int v=a[i].v;
				for(j=fir[v];j;j=a[j].next){
					int w=a[j].v;
					if(vis[w]>0){//满足三元环 
						int I,J,K,k=vis[w];
						I=find(i);J=find(j);K=find(k);
						f[I]=I;f[J]=I;f[K]=I;
					}
				}
			}
			for(i=fir[u];i;i=a[i].next){
				int v=a[i].v;
				vis[v]=0;
			}
		}
		int zuxian=find(1);ans=1;
		for(i=2;i<=m;i++){
			if(find(i)==zuxian)ans++;
		}
		if(ans==m)printf("Yes\n");
		else printf("No\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
