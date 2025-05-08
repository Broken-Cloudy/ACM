#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
};
nod a[400009];
int n,m,x,y,i,j,ans,du[100009],vis[100009],X[200009],Y[200009];
int fir[100009],cnt;//2是新图
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&X[i],&Y[i]);
		du[X[i]]++;du[Y[i]]++;
	}
	for(i=1;i<=m;i++){//建立新图 
		if(du[X[i]]==du[Y[i]])add(min(X[i],Y[i]),max(X[i],Y[i]));
		else add((du[X[i]]<du[Y[i]]?X[i]:Y[i]),(du[X[i]]<du[Y[i]]?Y[i]:X[i]));
	}
	for(int u=1;u<=n;u++){
		for(i=fir[u];i;i=a[i].next){
			int v=a[i].v;
			vis[v]=u;
		}
		for(i=fir[u];i;i=a[i].next){
			int v=a[i].v;
			for(j=fir[v];j;j=a[j].next){
				int w=a[j].v;
				if(vis[w]==u)ans++;
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
