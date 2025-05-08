#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
};
nod a[600009];
int fir[300009],cnt,x,y,val[300009],T,i,n,f[300009][2],sum,ans,ANS;
int vis[300009];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs(int u){
	int i;
	bool ff=0;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			ff=1;
			dfs(v);
			//选这个点 
			f[u][1]+=f[v][0];
			//不选这个点 
			f[u][0]+=max(f[v][0],f[v][1]);
		}
	}
	if(ff==0){
		f[u][1]=val[u];
		f[u][0]=0;
	}
	else{
		f[u][1]+=val[u];
		f[u][0]+=0;
	}
}
void DFS(int u,bool fff){//fff==1选择了1 
	int i;
	vis[u]=1;
	if(fff==true&&val[u]>0)val[u]=0;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			if(fff==true||val[u]==0){
				DFS(v,false);
			}
			else{
				if(f[v][1]>f[v][0]){
					DFS(v,true);
				}
				else DFS(v,false);
			}
		}
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;sum=0;ANS=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&val[i]);
			fir[i]=0;
			sum+=val[i];
		}
		for(i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
		}
		while(sum>0){
			for(i=1;i<=n;i++)vis[i]=f[i][0]=f[i][1]=0;
			dfs(1);
			ans=max(f[1][0],f[1][1]);
			for(i=1;i<=n;i++)vis[i]=0;
			if((f[1][0]<f[1][1]))DFS(1ULL,true);
			else DFS(1ULL,false);
			ANS+=sum;sum-=ans;
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
