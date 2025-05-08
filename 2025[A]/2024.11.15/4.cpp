#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,i,n,a[500009],maxx,L,R;
int tree[4000009],tag[4000009];
struct nod{
	int l,r,val;
}t,d;
deque<nod>q;
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
	tag[node]=k;
	tree[node]=(end-start+1)*k;//先把本层给加了，下面的层数先不加，打个标记 
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
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		while(!q.empty())q.pop_back();
		for(i=1;i<=8*n;i++)tag[i]=tree[i]=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		build(1,1,n);
		t.l=1;t.r=1;t.val=a[1];
		q.push_back(t);
		for(i=2;i<=n;i++){
			t=q.back();q.pop_back();
			maxx=t.val;L=t.l;R=i;
			if(a[i]>maxx){
				q.push_back(t);
				t.l=i;t.r=i;t.val=a[i];
				q.push_back(t);
			}
			else if(a[i]==maxx){
				t.l=L;t.r=i;t.val=maxx;
				q.push_back(t);
			}
			else{
				while(!q.empty()){
					d=q.back();
					if(a[i]<d.val){
						L=d.l;
						q.pop_back();
					}
					else{
						break;
					}
				}
				t.l=L;t.r=R;t.val=maxx;
				q.push_back(t);
				change(1,1,n,L,R,maxx);
			}
		}
		for(i=1;i<=n;i++){
			if(i!=n)printf("%lld ",sum(1,1,n,i,i));
			else printf("%lld\n",sum(1,1,n,i,i));
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
