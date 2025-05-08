#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,x,y,du[200009],types[200009],ANS,leaves,dian[200009];
struct nod{
	int next,u,v;
}a[400009];
int fir[200009],cnt,vis[400009],M[400009],Node[200009];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
inline void dfs(int edge){
	int i,u,last;
	u=a[edge].v;last=a[edge].u;
	if(vis[edge]==1){
		return;
	}
	else{
		if(types[last]==1)M[edge]++;
		vis[edge]=1;
	}
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(types[v]==2)continue;
		if(v==last)continue;
		if(Node[v])
		if(vis[i]==0){
			dfs(i);
		}
		M[edge]+=M[i];
	}
}
bool cmp(int x,int y){
	return y>x;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;
		for(i=1;i<=n;i++)fir[i]=0,types[i]=0,du[i]=0;
		for(i=1;i<=2*n;i++)vis[i]=M[i]=0;
		for(i=1;i<=n-1;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
			du[x]++;du[y]++;
		}
		//vis[i]=0Ê÷¸É 
		leaves=0;
		for(i=1;i<=n;i++){
			if(du[i]==1){
				types[i]=2;//Ò¶×Ó 
				leaves++;
				j=fir[i];
				types[a[j].v]=1;//Ò¶Ö¦
			}
		}
		for(i=1;i<=cnt;i++)dfs(i);
		ANS=leaves*(n-leaves);dian[0]=0;
		for(i=1;i<=n;i++)if(types[i]==0)dian[++dian[0]]=i;
		sort(dian+1,dian+1+dian[0],cmp);
		for(i=1;i<=dian[0];i++){
			for(j=fir[dian[i]];j;j=a[j].next){
				ANS+=M[j];
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
