#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
struct nod{
	int next,u,v;
};
ll tree[4000009];
nod a[600009];
int fir[300009],cnt,vis[300009],x,y,timer,intime[300009],outtime[300009];
void add(int u,int v){
	cnt++;
	a[cnt].next=fir[u];
	a[cnt].u=u;a[cnt].v=v;
	fir[u]=cnt;
}
int T,i,k,n,q,b[300009],p[300009];
void dfs(int x){
	int i;
	vis[x]=1;
	intime[x]=++timer;
	for(i=fir[x];i;i=a[i].next){
		int y=a[i].v;
		if(vis[y]==0){
			dfs(y);
		}
	}
	outtime[x]=++timer;
}
void build(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		tree[node]=intime[p[start]];//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build(zuo,start,mid);
		build(you,mid+1,end);
		tree[node]=max(tree[zuo],tree[you]);
	}
}
void pushup(int node,int start,int end){
	if(start!=end){
		int zuo=node*2;
		int you=node*2+1;
		tree[node]=max(tree[zuo],tree[you]);
	}
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		tree[node]=k;
		pushup(node,start,end);//加速操作!!!
		return;//记得return 
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k);
		change(you,mid+1,end,L,R,k);
		pushup(node,start,end);
	}
}
ll query(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return 0;//加速操作!!!
	else if(start>=L&&end<=R)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=query(zuo,start,mid,L,R);
		ll y=query(you,mid+1,end,L,R);
		pushup(node,start,end);//NlogN次 
		return max(x,y);
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&q);cnt=0;
		for(i=1;i<=n;i++)fir[i]=0,vis[i]=0;
		for(i=1;i<n;i++){
			scanf("%lld",&k);
			add(i+1,k);add(k,i+1);
		}
		timer=0;
		dfs(1);
		for(i=1;i<=n;i++){
			scanf("%lld",&b[i]);
			p[b[i]]=i;
		}
		build(1,1,n);
		while(q--){
			scanf("%lld%lld",&x,&y);
			swap(b[x],b[y]);
			p[b[x]]=x;p[b[y]]=y;
			change(1,1,n,x,x,intime[p[x]]);
			change(1,1,n,y,y,intime[p[y]]);
			if(query(1,1,n,1,n)==intime[p[1]]){
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
