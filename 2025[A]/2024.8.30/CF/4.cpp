#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y,n,i;
struct nod{
	int u,v,next;
	int x_or;
};
nod a[200009];
int fir[100009],vis[100009],cnt,f=0;
char c[100009];
void add(int x,int y){
	cnt++;
	a[i].u=x;a[i].v=y;a[i].next=fir[x];
	fir[x]=cnt;
}
void dfs(int u,int op){//op==1 Irics op==0 Dora
	int i;
	bool f=0;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			f=1;
			dfs(v,!op);
		}
	}
	if(f==0){
		
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;f=0;
		for(i=1;i<=n;i++)vis[i]=fir[i]=0;
		for(i=1;i<=n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
		}
		getchar();
		for(i=1;i<=n;i++){
			c[i]=getchar();
			//if(c[i]=='1'||c[i]=='0')f=i;
		}
		dfs(1,1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
