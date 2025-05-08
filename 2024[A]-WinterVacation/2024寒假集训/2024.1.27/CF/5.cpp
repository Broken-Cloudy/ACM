#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,q,i,tree[2000009],op,x,y,k;
bool f;
struct nod{
    ll dis,val;
    bool operator<(const nod &b)const{
		return dis<b.dis;
	}
    bool operator()(const nod x,const nod y){ //定义比较方式，这一步很重要
        return x.dis<y.dis;
    }
};
struct node{
	int val,id;
	bool operator < (const node &b) const{
		if(val!=b.val) 
			return val<b.val;
		else 
			return id<b.id;
	}
};
bool cmp(nod x,nod y){
	return x.dis<y.dis;
}
nod hab[300009];
void build(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		nod k;
		k.dis=start;k.val=0;
		ll d=upper_bound(hab+1,hab+1+m,k)-(hab+1);
		int X0=hab[d].dis,X1=hab[d+1].dis;
		if(start<hab[1].dis||start>hab[m].dis)tree[node]=0;
		if(start==X0||start==X1)tree[node]=0;
		else{
			tree[node]=hab[d].val*hab[d+1].dis;
		}
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
void change(ll node,ll start,ll end,ll x,ll k){
	if(end<x||start>x)return;//加速操作!!!
	else if(start==end&&start==x){
		add_tag(node,start,end,k);
		return;//记得return 
	} 
	else{
		//pushdown(node,start,end);//加值的时候也要下传，细化，否则可能会影响结果 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,x,k);
		change(you,mid+1,end,x,k);
		tree[node]=tree[zuo]+tree[you];
	}
}
ll sum(ll node,ll start,ll end,ll L,ll R){
	//pushdown(node,start,end);//NlogN次 
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
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>m>>q;
	for(i=1;i<=m;i++){
		scanf("%lld",&hab[i].dis);
	}
	for(i=1;i<=m;i++){
		scanf("%lld",&hab[i].val);
	}
	sort(hab+1,hab+1+m,cmp);
	build(1,1,n);
	for(i=1;i<q;i++){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld",&x,&k);
			change(1,1,n,x,k);
		}
		else if(op==2){
			scanf("%lld%lld",&x,&y);
			ll ans=sum(1,1,n,x,y);
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
