#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500009],tree[4000009],i,n,m,op,x,y,k,L,R,now,cnt,cntr,r;
ll tag[4000009];//Lazy tag 
bool f=0;
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
void minuss(int x,int y){
	if(r>y)r=r%(y-x+1);
	if(x+r+L-1>n){
		int p=(x+r+L-1)-n;//>=1
		change(1,1,n,x+r,y,-1);
		change(1,1,n,x,x+p-1,-1);
	}
	else change(1,1,n,x+r,x+r+L-1,-1);
}
int main(){
	freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	cin>>n>>L>>R;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]=(a[i]+1)/2;
	} 
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++){
		if(a[i]>1){
			cnt=i;
			break;
		}
	}
	build(1,1,n);
	now=1;
	while(now<=n){
		if(f==1)break;
		if(now+R-1>=n){
			f=1;
			printf("Yes\n");
			break;
		}
		else{
			if(cnt+L-1>n){
				f=1;
				printf("No\n");
				break;
			}
			while(sum(1,1,n,cnt,cnt)<=1){
				cnt++;r--;
				if(cnt+L-1>n){
					f=1;
					printf("No\n");
					break;
				}
		
			}
			minuss(cnt,n);
			r+=L;
			now+=(R-L);
		}
	}
	if(now+R-1>=n){
		f=1;
		printf("Yes\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
