#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int next,u,v;
}a[200009];
int ans[100009],anss[100009];
int fir[100009],vis[100009],cnt,i,j,x,y,t,N,val,point[100009];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs(int u){
	int i;
	vis[u]=1;ans[++ans[0]]=u;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(v!=-1){
			if(vis[v]==0){
				dfs(v);
			}
		}
	}
}
void putout(int x){
	if(x>=10000)printf("%lld",x);
	else if(x>=1000)printf("0%lld",x);
	else if(x>=100)printf("00%lld",x);
	else if(x>=10)printf("000%lld",x);
	else printf("0000%lld",x);
}
signed main(){
	freopen("126.in","r",stdin);freopen("126.out","w",stdout);
	scanf("%lld%lld",&t,&N);
	for(i=1;i<=N;i++){
		scanf("%lld%lld%lld",&x,&val,&y);
		add(x,y);add(y,x);point[x]=val;
	}
	dfs(t);i=1;j=ans[0];
	while(i<=j){
		anss[++anss[0]]=ans[j];
		if(i!=j)anss[++anss[0]]=ans[i];
		i++;j--;
	}
	for(i=1;i<=anss[0];i++){
		putout(anss[i]);printf(" %lld ",point[anss[i]]);
		if(i<anss[0])putout(anss[i+1]);
		else printf("-1");
		putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
