#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll a[4000009],tree[4000009],i,n,m,op,x,y,k,q,bh[100009],j,num;
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
		tree[node]=min(tree[zuo],tree[you]);
	}
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		tree[node]=k;
		return;//记得return 
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k);
		change(you,mid+1,end,L,R,k);
		tree[node]=min(tree[zuo],tree[you]);
	}
}
//L是目标左 R是目标右[L,R]
//start是当前正在查询的起始点，end是当前正在查询的结束点
//当前正在查询[start,end] 
ll sum(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return 1000000009LL;//加速操作!!!
	else if(start>=L&&end<=R)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum(zuo,start,mid,L,R);
		ll y=sum(you,mid+1,end,L,R);
		return min(x,y);
	}
}
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&m);num+=m;
		bh[i]=bh[i-1]+m;
		for(j=1;j<=m;j++){
			scanf("%lld",&a[bh[i-1]+j]);
		}
	} 
	for(i=1;i<=8*num;i++)tree[i]=1000000009LL;
	build(1,1,num);
	cin>>q;
	while(q--){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			int BH=bh[x-1]+y;
			change(1,1,num,BH,BH,k);
		}
		else{
			scanf("%lld",&x);
			int BH=bh[x];
			ll ans=sum(1,1,num,1,BH);
			printf("%lld\n",ans);//1是根结点，就是sum[1,n] 
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
