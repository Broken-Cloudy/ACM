#include<bits/stdc++.h>
#define int long long
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
struct nod{
	int ch[2];
}tree[59];
using namespace std;
int mid[59],bef[59],i,n,bh[59],ans[59];
queue<int>q;
void dfs(int node,int start,int end){
	int u=bef[node];
	int len1=bh[u]-start;//×ó 
	int len2=end-bh[u];
	if(len1>0)dfs(node+1,start,bh[u]-1),lc(u)=bef[node+1];//×ó 
	if(len2>0)dfs(node+1+len1,bh[u]+1,end),rc(u)=bef[node+1+len1];
}
signed main(){
	freopen("115.in","r",stdin);freopen("115.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&mid[i]),bh[mid[i]]=i;
	for(i=1;i<=n;i++)scanf("%lld",&bef[i]);
	dfs(1,1,n);q.push(bef[1]);
	while(!q.empty()){
		int u=q.front();q.pop();
		ans[++ans[0]]=u;
		if(rc(u)>0)q.push(rc(u));
		if(lc(u)>0)q.push(lc(u));
	}
	for(i=1;i<=ans[0];i++){
		if(i==ans[0])printf("%lld",ans[i]);
		else printf("%lld ",ans[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
