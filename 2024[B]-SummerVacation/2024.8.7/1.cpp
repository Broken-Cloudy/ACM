#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,n,a[200009],m,x,y,i;
int tag[800009],tree[800009];
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
		tree[node]=tree[zuo]+tree[you];
	}
}
void add_tag(ll node,ll start,ll end){//懒人标记 
	tag[node]=1;
	tree[node]=(end-start+1);//先把本层给加了，下面的层数先不加，打个标记 
	return;
}
void pushdown(ll node,ll start,ll end){//只需执行一次 
	if(tag[node]==0)return;//没有标记，不需要考虑
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		add_tag(zuo,start,mid);//标记下传(标记并不是去除，而是下传) 
		add_tag(you,mid+1,end);//标记下传(标记并不是去除，而是下传) 
		tag[node]=0;//标记清空 
	} 
}
void change(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		add_tag(node,start,end);
		return;//记得return 
	} 
	else{
		pushdown(node,start,end);//加值的时候也要下传，细化，否则可能会影响结果 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R);
		change(you,mid+1,end,L,R);
		tree[node]=tree[zuo]+tree[you];
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
		return x+y;
	}
}
int ans1,ans2,ans3,sum1,sum2;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(i=0;i<=n;i++)a[i]=0;
		build(1,1,n);
		for(i=1;i<=m;i++){
			scanf("%lld%lld",&x,&y);
			ans1=sum(1,1,n,1,x);ans2=sum(1,1,n,y,n);ans3=sum(1,1,n,x,y);
			sum1=min((x-1+1)+(n-y+1)-(ans1+ans2),(x-1+1)+(n-y+1)-1);
			sum2=min((y-x+1)-ans3,(y-x+1)-1);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
