#include<bits/stdc++.h>
#define ll int
using namespace std;
deque<int>d;
int T,i,n,a[500009],zuo[500009],zuocnt,you[500009],youcnt,t;
int tree[4000009],tag[4000009];
void PRE(){
	zuocnt=youcnt=0;
	for(i=n;i>=1;i--){//针对左 
		while(!d.empty()){
			t=d.back();
			if(t>=a[i])d.pop_back();
			else break;
		}
		d.push_back(a[i]);
	}
	while(!d.empty()){//形成单调减 
		t=d.front();d.pop_front();
		zuo[++zuocnt]=t;
	}
	for(i=1;i<=n;i++){//针对右 
		while(!d.empty()){
			t=d.back();
			if(t<=a[i])d.pop_back();
			else break;
		}
		d.push_back(a[i]);
	}
	while(!d.empty()){//形成单调增 
		t=d.front();d.pop_front();
		you[++youcnt]=t;
	}
	for(i=1;i<=8*n;i++)tag[i]=tree[i]=0LL;
}
void add_tag(ll node,ll start,ll end,ll k){//懒人标记 
	tag[node]+=k;
	tree[node]+=k;//先把本层给加了，下面的层数先不加，打个标记 
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
		tree[node]=max(tree[zuo],tree[you]);
	}
}
ll sum(ll node,ll start,ll end,ll L,ll R){
	pushdown(node,start,end);//NlogN次 
	if(end<L||start>R)return 0LL;//加速操作!!!
	else if(start>=L&&end<=R)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum(zuo,start,mid,L,R);
		ll y=sum(you,mid+1,end,L,R);
		return max(x,y);
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		PRE();
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
