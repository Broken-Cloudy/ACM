#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int n,m,i,a[200009],T,ANS;
ll tree[1600009];
ll tag[1600009];//Lazy tag 
void add_tag(ll node,ll start,ll end,ll k){//懒人标记 
	tag[node]+=k;
	tree[node]+=(end-start+1)*k;//先把本层给加了，下面的层数先不加，打个标记 
	return;
}
void pushdown(ll node,ll start,ll end){//只需执行一次 
	if(tag[node]==0)return;//没有标记，不需要考虑
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag[node];
		add_tag(zuo,start,mid,t);//标记下传(标记并不是去除，而是下传) 
		add_tag(you,mid+1,end,t);//标记下传(标记并不是去除，而是下传) 
		tag[node]=0;//标记清空 
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
		tree[node]=tree[zuo]+tree[you];
	}
}
//L是目标左 R是目标右[L,R]
//start是当前正在查询的起始点，end是当前正在查询的结束点
//当前正在查询[start,end] 
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
bool cmp1(int x,int y){
	return x<y;
}
bool cmp2(int x,int y){
	return x>y;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);ANS=0;
		for(i=1;i<=8*n;i++)tag[i]=tree[i]=0;
		for(i=1;i<=m;i++)scanf("%lld",&a[i]);
		sort(a+1,a+1+m,cmp1);
		for(i=1;i<=m;i++){
			ANS+=sum(1,1,n-1,max(1LL,n-a[i]),n-1);
			change(1,1,n-1,1,min(n-1,a[i]),1);
		}
		printf("%lld\n",ANS*2LL);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
