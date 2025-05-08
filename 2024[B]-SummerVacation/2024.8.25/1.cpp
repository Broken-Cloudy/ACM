#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
};
nod a[1000009];
int cnt,fir[500009],vis[500009],fa[500009],depth[500009];
int n,q,s,r,i,j,x,y,dp[500009][21],pow2[61],log_2[500009];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs(int u,int deep){
	int i;
	vis[u]=1;depth[u]=deep;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			fa[v]=u;
			dfs(v,deep+1);
		}
	}
}
//都是先大跳，再小跳 
//16+8+4+2+1+4+2+4+1这样子可以跳出完整数字 
int lca(int u,int v){
	int i,len;
	if(depth[u]<depth[v])swap(u,v);//我要depth[u]大 
	len=log_2[depth[u]-depth[v]];//向上跳2^len(这个是向下取整) 
	//深的先向上跳 
	for(i=len;i>=0;i--)if(depth[u]-pow2[i]>=depth[v])u=dp[u][i];
	if(u==v)return u;
	else{//一起向上跳 
		len=log_2[depth[u]];//选哪个都行 
		for(i=len;i>=0;i--){
			if(dp[u][i]==dp[v][i]){
				continue;
			}
			else{
				u=dp[u][i];
				v=dp[v][i];
			}
		}
		//选哪个都行 
		return fa[u];//上面的if就已经排除了一个是另一个祖先的情况
		//没办法，dp数组只能处理到2^0==1跳一位，所以要手动输出fa 
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>q>>s;pow2[0]=1;log_2[0]=-1;log_2[1]=0;r=4;j=1;
	for(i=1;i<=59;i++)pow2[i]=pow2[i-1]*2;//2^...
	for(i=2;i<=500000;i++){
		if(i>=r)r*=2,j++;
		log_2[i]=j;
	}
	for(i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(s,1);//根节点 
	for(i=1;i<=n;i++)dp[i][0]=fa[i];
	for(j=1;pow2[j]<=n;j++){//logn
		for(i=1;i<=n;i++){//n
			if(depth[i]>pow2[j])dp[i][j]=dp[dp[i][j-1]][j-1];
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		int t=lca(x,y);
		printf("%lld\n",t);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
