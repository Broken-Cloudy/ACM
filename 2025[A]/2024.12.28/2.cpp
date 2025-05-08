#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
struct nod{
	int r,l,len,bh;
}a[200009];
int T,i,n,FF[200009],vis[400009];
int tree[4000009];
bool cmp(nod x,nod y){
	return x.len<y.len;
}
void build(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		tree[node]=0LL;//或return a[end] 
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
void change(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		tree[node]=1;
		return;//记得return 
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R);
		change(you,mid+1,end,L,R);
		tree[node]=min(tree[zuo],tree[you]);
	}
}
ll sum(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return 1LL;//加速操作!!!
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
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld%lld",&a[i].l,&a[i].r);
			a[i].len=a[i].r-a[i].l;a[i].bh=i;
			vis[i]=vis[i+n]=0;FF[i]=0;
		}
		sort(a+1,a+1+n,cmp);
		build(1,1,2*n);
		for(i=1;i<=n;i++){
			int check=sum(1,1,2*n,a[i].l,a[i].r);
			if(check==1){
				FF[a[i].bh]=0;
				if(a[i].l==a[i].r){
					FF[vis[a[i].l]]=0;
				}
			}
			else{
				FF[a[i].bh]=1;
				if(a[i].l==a[i].r){
					change(1,1,2*n,a[i].l,a[i].r);
					vis[a[i].l]=a[i].bh;
				}
			}
		}
		for(i=1;i<=n;i++){
			if(FF[i]==1)putchar('1');
			else putchar('0');
		}
		putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
