#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[200009];
struct node{
	int bh,val;
}p[100009];
int fir[100009],i,cnt,x,y,n,vis[100009],maxx,k,bh;
bool cmp(node x,node y){
	if(x.val==y.val)return x.bh>y.bh;
	else return x.val>y.val;
}
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs(int u){
	int i,num=0;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			num++;
			dfs(v);
		}
	}
	if(u==1){p[u].val=num;p[u].bh=u;}
	else{p[u].val=num+1;p[u].bh=u;}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;
	for(i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1);sort(p+1,p+1+n,cmp);
	maxx=p[1].val;bh=9999999LL;
	for(i=2;i<=n;i++)if(p[i].val<maxx)bh=min(bh,p[i].bh);
	k=max(1LL,maxx-1LL);if(n==2)bh=1;
	printf("%lld %lld\n",k,bh);
	fclose(stdin);fclose(stdout);
	return 0;
}
