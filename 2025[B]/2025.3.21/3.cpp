#include<bits/stdc++.h>
#define ll int
using namespace std;
int n,q,a[100009],i,op,l,r,x,anss,FF,b[109];
struct nod{
	int max,min,num;
}tree[1600009],d;
int tag[1600009];
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
void add_tag(ll node,ll start,ll end,ll k){
	tag[node]=k;tree[node].max=k;tree[node].min=k;
	return;
}
void pushdown(ll node,ll start,ll end){
	if(tag[node]==0)return;
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag[node];
		add_tag(zuo,start,mid,t);
		add_tag(you,mid+1,end,t);
		tag[node]=0;
	}
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(start>R||end<L)return;
	else if(start>=L&&end<=R){
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
		tree[node].max=max(tree[zuo].max,tree[you].max);
		tree[node].min=min(tree[zuo].min,tree[you].min);
	}
}
nod sum(ll node,ll start,ll end,ll L,ll R){
	nod t;t.max=-1;t.min=36501;t.num=0;
	pushdown(node,start,end);
	if(end<L||start>R)return t;
	else if(start>=L&&end<=R){
		t=tree[node];t.num=end-start+1;
		return t;
	}
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		nod x=sum(zuo,start,mid,L,R);
		nod y=sum(you,mid+1,end,L,R);
		t.max=max(x.max,y.max);t.min=min(x.min,y.min);t.num=x.num+y.num;
		return t;
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	while(q--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d",&l,&r,&x);
			change(1,1,n,l,r,x);
		}
		else{
			scanf("%d%d",&l,&r);
			if(l==r){
				printf("0 0\n");
			}
			else if(r-l<=100){
				FF=0;b[0]=0;
				d=sum(1,1,n,l,r);
				anss=d.max-d.min;
				for(i=l;i<=r;i++)b[++b[0]]=sum(1,1,n,i,i).max;
				sort(b+1,b+1+b[0]);
				for(i=1;i<b[0];i++)if(b[i+1]-b[i]<365)FF=1;
				if(anss>365){
					if(FF==1)printf("1 1\n");
					else printf("1 0\n");
				}
				else{
					if(FF==1)printf("0 1\n");
					else printf("0 0\n");
				}
			}
			else{
				d=sum(1,1,n,l,r);
				anss=d.max-d.min;
				if(anss>365)printf("1 1\n");
				else printf("0 1\n");
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
