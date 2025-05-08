#include<bits/stdc++.h>
#define ll int
using namespace std;
int n,q,a[100009],i,op,l,r,x;
struct nod{
	int max,min;
}tree[1600009];
void build(ll node,ll start,ll end){
	if(start==end){
		tree[node].max=a[start];
		tree[node].min=a[start];
		return;
	}
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		build(zuo,start,mid);
		build(you,mid+1,end);
		tree[node].max=max(tree[zuo].max,tree[you].max);
		tree[node].min=min(tree[zuo].min,tree[you].min);
	}
}
nod sum(ll node,ll start,ll end,ll L,ll R){
	nod t;t.max=-1;t.min=36501;
	if(end<L||start>R)return t;
	else if(start>=L&&end<=R)return tree[node];
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		nod x=sum(zuo,start,mid,L,R);
		nod y=sum(you,mid+1,end,L,R);
		t.max=max(x.max,y.max);t.min=(x.min,y.min);
		return t;
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	while(q--){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld%lld",&l,&r,&x);
			
		}
		else{
			scanf("%lld%lld%lld",&l,&r);
			if(r-l>=101){
				
			}
			else{
				
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
