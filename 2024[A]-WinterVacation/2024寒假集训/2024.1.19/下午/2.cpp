#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[4000009],tree[4000009],i,n,m,op,x,y,k,q;
ll tag[4000009],tag2[4000009];//Lazy tag 
void build(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		tree[node]=a[start]%m;//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build(zuo,start,mid);
		build(you,mid+1,end);
		tree[node]=tree[zuo]%m+tree[you]%m;
	}
}
void add_tag(ll node,ll start,ll end,ll k){//懒人标记 
	tag[node]+=k;
	tree[node]+=(end-start+1)*k;//先把本层给加了，下面的层数先不加，打个标记 
	tree[node]%=m;
	return;
}
void multi_tag(ll node,ll start,ll end,ll k){
	tag2[node]*=k;
	tag2[node]%=m;//
	tag[node]*=k;//加法也会被作用 
	tag[node]%=m;//
	tree[node]*=k;//先把本层给乘了，下面的层数先不乘，打个标记 
	tree[node]%=m;// 
	return;
}
void pushdown(ll node,ll start,ll end){//只需执行一次 
	if(tag[node]==0&&tag2[node]==1)return;//没有标记，不需要考虑
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag[node];//加法 
		ll d=tag2[node];//乘法 
		multi_tag(zuo,start,mid,d);//已经默认加法在后面 
		add_tag(zuo,start,mid,t);//标记下传(标记并不是去除，而是下传) 
		multi_tag(you,mid+1,end,d);
		add_tag(you,mid+1,end,t);//标记下传(标记并不是去除，而是下传) 
		tag[node]=0;//标记清空 
		tag2[node]=1; 
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
		tree[node]=tree[zuo]%m+tree[you]%m;
		tree[node]%=m;
	}
}
void change2(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		multi_tag(node,start,end,k);
		return;//记得return 
	} 
	else{
		pushdown(node,start,end);//细化，否则可能会影响结果 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change2(zuo,start,mid,L,R,k);
		change2(you,mid+1,end,L,R,k);
		tree[node]=tree[zuo]%m+tree[you]%m;
		tree[node]%=m;
	}
}
ll sum(ll node,ll start,ll end,ll L,ll R){
	pushdown(node,start,end);//NlogN次 
	if(end<L||start>R)return 0;//加速操作!!!
	else if(start>=L&&end<=R)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum(zuo,start,mid,L,R);
		ll y=sum(you,mid+1,end,L,R);
		x%=m;y%=m;
		return (x+y)%m;
	}
}
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>q>>m;
	for(i=1;i<=400000;i++)tag2[i]=1;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]%=m;
	}
	build(1,1,n);
	for(i=1;i<=q;i++){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			change2(1,1,n,x,y,k);
		}
		else if(op==2){
			scanf("%lld%lld%lld",&x,&y,&k);
			change(1,1,n,x,y,k);
		}
		else{
			scanf("%lld%lld",&x,&y);
			ll ans=sum(1,1,n,x,y);
			printf("%lld\n",ans%m);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
