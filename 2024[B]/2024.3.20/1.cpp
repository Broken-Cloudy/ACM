#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e18+7;
ll a[7000009],tree[7000009],i,n,m,op,x,y,k;
ll tag[7000009],tag2[7000009];//Lazy tag 
void build(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		tree[node]=a[start];//或return a[end] 
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
void add_tag(ll node,ll start,ll end,ll k){//懒人标记 
	if(tag2[node]==inf){
		tag[node]+=k;
		tree[node]+=k;
	}
	else{
		tag2[node]+=k;
		tree[node]+=k;//先把本层给加了，下面的层数先不加，打个标记 
	}
	return;
}
void change_tag(ll node,ll start,ll end,ll k){//懒人标记 
	tag2[node]=k;
	tag[node]=0;//加法被清除 
	tree[node]=k;
	return;
}
void pushdown(ll node,ll start,ll end){//只需执行一次 
	if(tag[node]==0&&tag2[node]==inf)return;//没有标记，不需要考虑
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		if(tag[node]!=0){
			ll t=tag[node];
			add_tag(zuo,start,mid,t);//标记下传(标记并不是去除，而是下传) 
			add_tag(you,mid+1,end,t);//标记下传(标记并不是去除，而是下传) 
			tag[node]=0;//标记清空 
			tag2[node]=inf;
		}
		else if(tag2[node]!=inf){
			ll t2=tag2[node];
			change_tag(zuo,start,mid,t2);//标记下传(标记并不是去除，而是下传) 
			change_tag(you,mid+1,end,t2);//标记下传(标记并不是去除，而是下传) 
			tag[node]=0;//标记清空 
			tag2[node]=inf;
		}
	} 
}
void make_change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		change_tag(node,start,end,k);
		return;//记得return 
	} 
	else{
		pushdown(node,start,end);//加值的时候也要下传，细化，否则可能会影响结果 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		make_change(zuo,start,mid,L,R,k);
		make_change(you,mid+1,end,L,R,k);
		tree[node]=max(tree[zuo],tree[you]);
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
		tree[node]=max(tree[zuo],tree[you]);
	}
}
//L是目标左 R是目标右[L,R]
//start是当前正在查询的起始点，end是当前正在查询的结束点
//当前正在查询[start,end] 
ll getmax(ll node,ll start,ll end,ll L,ll R){
	pushdown(node,start,end);//NlogN次 
	if(end<L||start>R)return -inf;//加速操作!!!
	else if(start>=L&&end<=R)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=getmax(zuo,start,mid,L,R);
		ll y=getmax(you,mid+1,end,L,R);
		return max(x,y);
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=7000000;i++)tree[i]=inf;
	for(i=1;i<=7000000;i++)tag2[i]=inf;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	build(1,1,n);
	for(i=1;i<=m;i++){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			make_change(1,1,n,x,y,k);
		}
		else if(op==2){
			scanf("%lld%lld%lld",&x,&y,&k);
			change(1,1,n,x,y,k);
		}
		else{
			scanf("%lld%lld",&x,&y);
			ll ans=getmax(1,1,n,x,y);
			printf("%lld\n",ans);//1是根结点，就是sum[1,n] 
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
