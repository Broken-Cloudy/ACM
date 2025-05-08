#include<bits/stdc++.h>
#define int long long
#define lc(x) tree[x].child[0]
#define rc(x) tree[x].child[1]
using namespace std;
struct nod{
	int child[2];
}tree[39];
int n,i,mid[59],after[59],bh[59],ans[59];
queue<int>q;
void dfs(int node,int start,int end){//start--end中序遍历 
	int u=after[node];
	int len1=end-bh[u];//右长 
	int len2=bh[u]-start;//左长(可以不写) 
	if(len1>0)dfs(node-1,bh[u]+1,end),rc(u)=after[node-1];//右
	if(len2>0)dfs(node-len1-1,start,bh[u]-1),lc(u)=after[node-len1-1];//左 
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&after[i]);
	for(i=1;i<=n;i++)scanf("%lld",&mid[i]),bh[mid[i]]=i;
	dfs(n,1,n);q.push(after[n]);
	while(!q.empty()){
		int u=q.front();q.pop();
		ans[++ans[0]]=u;
		if(lc(u)>0)q.push(lc(u));
		if(rc(u)>0)q.push(rc(u));
	}
	for(i=1;i<=n;i++){
		if(i==n)printf("%lld",ans[i]);
		else printf("%lld ",ans[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
