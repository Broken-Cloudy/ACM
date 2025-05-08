#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const ll MAXN=3e6+8;
ll n,m,a[MAXN*4],treea[MAXN*4],i,op,x,y,k,ans;//treea[MAXN*4]就是mini[MAXN*4]
ll tag1[MAXN*4];//tag2_min[MAXN*4]
//hismini[MAXN*4]就是以前的treeb[MAXN*4] 
ll tag2_hismin[MAXN*4],hismini[MAXN*4];
void add_tag(ll node,ll start,ll end,ll k){
	//原来的treea未下传 改值还在父结点上 
	tag2_hismin[node]=min(tag2_hismin[node],tag1[node]+tag2_hismin[node/2]);
	hismini[node]=min(hismini[node],treea[node]+tag2_hismin[node/2]);
	//下传 
	tag1[node]+=k;
	treea[node]+=k;//当前结点就表示一个区间最小值，只需要加k 
	return;
}
void pushdown(ll node,ll start,ll end){//只需执行一次 
	if(tag1[node]==0)return;//没有标记，不需要考虑
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag1[node];
		add_tag(zuo,start,mid,t);//标记下传(标记并不是去除，而是下传) 
		add_tag(you,mid+1,end,t);//标记下传(标记并不是去除，而是下传)
		tag1[node]=0;//标记清空 
	} 
}
void build_tree(ll node,ll start,ll end){
	if(start==end){
		treea[node]=a[start];
		return;
	}
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		build_tree(zuo,start,mid);
		build_tree(you,mid+1,end);
		treea[node]=min(treea[zuo],treea[you]);//区间最小值 
	}
}
ll mini(ll node,ll start,ll end,ll L,ll R){//返回最小值 
	pushdown(node,start,end);
	if(end<L||start>R)return 0;
	else if(end<=R&&start>=L)return treea[node];
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll x=mini(zuo,start,mid,L,R);
		ll y=mini(you,mid+1,end,L,R);
		return min(x,y);
	}
}
ll hism(ll node,ll start,ll end,ll L,ll R){//返回最小值 
	pushdown(node,start,end);
	if(end<L||start>R)return 0;
	else if(end<=R&&start>=L)return hismini[node];
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll x=hism(zuo,start,mid,L,R);
		ll y=hism(you,mid+1,end,L,R);
		return min(x,y);
	}
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;
	else if(end<=R&&start>=L){
		add_tag(node,start,end,k);
		return;
	}
	else{
		pushdown(node,start,end);
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k);
		change(you,mid+1,end,L,R,k);
		treea[node]=min(treea[zuo],treea[you]);//pushup 
		hismini[node]=min(hismini[zuo],hismini[you]);
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		//cin>>a[i];
		scanf("%lld",&a[i]);
	}
	build_tree(1,1,n);
	memcpy(hismini,treea,sizeof(treea));
	for(i=1;i<=m;i++){
		//cin>>op;
		scanf("%lld",&op);
		if(op==1){//区间加 
			//cin>>x>>y>>k;
			scanf("%lld%lld%lld",&x,&y,&k);
			change(1,1,n,x,y,k);
		}
		else if(op==2){
			//cin>>x>>y;
			scanf("%lld%lld",&x,&y);
			ans=mini(1,1,n,x,y);
			printf("%lld\n",ans);
		}
		else{
			//cin>>x>>y;
			scanf("%lld%lld",&x,&y);
			ans=hism(1,1,n,x,y);
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
