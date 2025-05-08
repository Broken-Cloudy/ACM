#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,n,m,op,x,y;
struct nod{
	int L,R;
}Tree[4000009],Tag[4000009];
double tree[4000009],a[4000009],tag[4000009],len,k;
void build2(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		Tree[node].L=start;//或return a[end] 
		Tree[node].R=end;//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build2(zuo,start,mid);
		build2(you,mid+1,end);
	}
}
void add_tag2(ll node,ll start,ll end,ll LL,ll RR){//懒人标记 
	Tag[node].L=LL;Tag[node].R=RR;
	Tree[node].L=LL;//先把本层给加了，下面的层数先不加，打个标记 
	Tree[node].R=RR;
	return;
}
void pushdown2(ll node,ll start,ll end){//只需执行一次 
	if(Tag[node].L==0&&Tag[node].R==0)return;//没有标记，不需要考虑
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		add_tag2(zuo,start,mid,Tag[node].L,Tag[node].R);//标记下传(标记并不是去除，而是下传) 
		add_tag2(you,mid+1,end,Tag[node].L,Tag[node].R);//标记下传(标记并不是去除，而是下传) 
		Tag[node].L=0;Tag[node].R=0;//标记清空 
	} 
}
void change2(ll node,ll start,ll end,ll L,ll R,ll LL,ll RR){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		add_tag2(node,start,end,LL,RR);
		return;//记得return 
	} 
	else{
		pushdown2(node,start,end);//加值的时候也要下传，细化，否则可能会影响结果 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change2(zuo,start,mid,L,R,LL,RR);
		change2(you,mid+1,end,L,R,LL,RR);
	}
}
nod sum2(ll node,ll start,ll end,ll L,ll R){
	nod p;p.L=99999999LL;p.R=0;
	pushdown2(node,start,end);//NlogN次 
	if(end<L||start>R)return p;//加速操作!!!
	else if(start>=L&&end<=R)return Tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		nod x=sum2(zuo,start,mid,L,R);
		nod y=sum2(you,mid+1,end,L,R);
		p.L=min(x.L,y.L);p.R=max(x.R,y.R);
		return p;
	}
}
//L是目标左 R是目标右[L,R]
//start是当前正在查询的起始点，end是当前正在查询的结束点
//当前正在查询[start,end] 
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
void add_tag(ll node,ll start,ll end,double k){//懒人标记 
	tag[node]=k;
	tree[node]=(end-start+1.0)*k;//先把本层给加了，下面的层数先不加，打个标记 
	return;
}
void pushdown(ll node,ll start,ll end){//只需执行一次 
	if(tag[node]==0)return;//没有标记，不需要考虑
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		double t=tag[node];
		add_tag(zuo,start,mid,t);//标记下传(标记并不是去除，而是下传) 
		add_tag(you,mid+1,end,t);//标记下传(标记并不是去除，而是下传) 
		tag[node]=0;//标记清空 
	} 
}
void change(ll node,ll start,ll end,ll L,ll R,double k){
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
		tree[node]=tree[zuo]+tree[you];
	}
}
//L是目标左 R是目标右[L,R]
//start是当前正在查询的起始点，end是当前正在查询的结束点
//当前正在查询[start,end] 
double sum(ll node,ll start,ll end,ll L,ll R){
	pushdown(node,start,end);//NlogN次 
	if(end<L||start>R)return 0.0;//加速操作!!!
	else if(start>=L&&end<=R)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		double x=sum(zuo,start,mid,L,R);
		double y=sum(you,mid+1,end,L,R);
		return x+y;
	}
}
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	} 
	build(1,1,n);build2(1,1,n);
	for(i=1;i<=m;i++){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld",&x,&y);
			nod t1=sum2(1,1,n,x,x);
			nod t2=sum2(1,1,n,y,y);
			len=t2.R-t1.L+1;
			double SUM=sum(1,1,n,t1.L,t2.R);
			k=SUM/len;
			change(1,1,n,t1.L,t2.R,k);
			change2(1,1,n,t1.L,t2.R,t1.L,t2.R);
		}
		else{
			scanf("%lld",&x);
			double ans=sum(1,1,n,x,x);
			printf("%.8lf\n",ans);//1是根结点，就是sum[1,n] 
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
