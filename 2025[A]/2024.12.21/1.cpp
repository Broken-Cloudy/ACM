#include<bits/stdc++.h>
#define int unsigned long long
#define ll unsigned long long
using namespace std;
const int MAXX=2e5+9;
const int INF=1e20+9;
int T,n,a[MAXX],b[MAXX],i,l,r,dd,kk,mini,ans;
int tree_min[8*MAXX],tree[8*MAXX],tag[8*MAXX];
void build_min(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		tree_min[node]=b[start];//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build_min(zuo,start,mid);
		build_min(you,mid+1,end);
		tree_min[node]=min(tree_min[zuo],tree_min[you]);
	}
}
ll sum_min(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return INF;//加速操作!!!
	else if(start>=L&&end<=R)return tree_min[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum_min(zuo,start,mid,L,R);
		ll y=sum_min(you,mid+1,end,L,R);
		return min(x,y);
	}
}
void build(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		tree[node]=1;//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build(zuo,start,mid);
		build(you,mid+1,end);
	}
}
void add_tag(ll node,ll start,ll end,ll k){//懒人标记 
	if(tag[node]>INF/k)tag[node]=INF;
	else tag[node]*=k;
	if(tree[node]>INF/k)tree[node]=INF;
	else tree[node]*=k;
	return;
}
void pushdown(ll node,ll start,ll end){//只需执行一次 
	if(tag[node]==1)return;//没有标记，不需要考虑
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag[node];
		add_tag(zuo,start,mid,t);//标记下传(标记并不是去除，而是下传) 
		add_tag(you,mid+1,end,t);//标记下传(标记并不是去除，而是下传) 
		tag[node]=1;//标记清空 
	} 
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		add_tag(node,start,end,k);
		return;//记得return 
	}
	else{
		pushdown(node,start,end);//加值的时候也要下传，细化，否则可能会影响结果 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k);
		change(you,mid+1,end,L,R,k);
	}
}
//L是目标左 R是目标右[L,R]
//start是当前正在查询的起始点，end是当前正在查询的结束点
//当前正在查询[start,end] 
ll sum(ll node,ll start,ll end,ll L,ll R){
	pushdown(node,start,end);//NlogN次 
	if(end<L||start>R)return 1LL;//加速操作!!!
	else if(start>=L&&end<=R)return tree[node];
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum(zuo,start,mid,L,R);
		ll y=sum(you,mid+1,end,L,R);
		if(x>INF/y)return INF;
		else return x*y;
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%llu",&n);ans=0;
		for(i=1;i<=8*n;i++){
			tree[i]=tree_min[i]=0;tag[i]=1;
		}
		for(i=1;i<=n;i++)scanf("%llu",&a[i]);
		for(i=1;i<=n;i++)scanf("%llu",&b[i]);
		build_min(1,1,n);build(1,1,n);
		l=1;r=n;
		while(l<=r){
			dd=sum(1,1,n,l,l);
			while(l<=r&&dd>=a[l]){
				l++;dd=sum(1,1,n,l,l);
			}
			kk=sum(1,1,n,r,r);
			while(l<=r&&kk>=a[r]){
				r--;kk=sum(1,1,n,r,r);
			}
			if(l>r)break;
			mini=sum_min(1,1,n,l,r);
			change(1,1,n,l,r,mini);ans++;
		}
		printf("%llu\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
