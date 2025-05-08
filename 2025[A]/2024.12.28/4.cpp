#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int P=998244353LL;
struct nod{
	int val,bh;
}a[200009],b[200009];
bool cmp(nod x,nod y){
	return x.val<y.val;
}
int T,n,q,i,o,x,ai[200009],bi[200009],c[200009],d,t;
int A[200009],B[200009];
int tree[1600009];
void build(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		tree[node]=c[start];//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build(zuo,start,mid);
		build(you,mid+1,end);
		tree[node]=(tree[zuo]*tree[you])%P;
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
		tree[node]=(tree[zuo]*tree[you])%P;
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
		return (x*y)%P;
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&q);
		for(i=1;i<=n;i++)scanf("%lld",&a[i].val),a[i].bh=i;
		for(i=1;i<=n;i++)scanf("%lld",&b[i].val),b[i].bh=i;
		sort(a+1,a+1+n,cmp);sort(b+1,b+1+n,cmp);
		for(i=1;i<=n;i++){
			ai[a[i].bh]=i;
			bi[b[i].bh]=i;
			A[i]=a[i].val;B[i]=b[i].val;
			c[i]=min(A[i],B[i]);
		}
		build(1,1,n);printf("%lld ",sum(1,1,n,1,n));
		while(q--){
			scanf("%lld%lld",&o,&x);
			if(o==1){
				t=ai[x];
				d=upper_bound(A+1,A+1+n,A[t])-(A+1);
				swap(ai[a[t].bh],ai[a[d].bh]);swap(a[t].bh,a[d].bh);
				A[d]++;
				c[d]=min(A[d],B[d]);
			}
			else{
				t=bi[x];
				d=upper_bound(B+1,B+1+n,B[t])-(B+1);
				swap(bi[b[t].bh],bi[b[d].bh]);swap(b[t].bh,b[d].bh);
				B[d]++;
				c[d]=min(A[d],B[d]);
			}
			change(1,1,n,d,d,c[d]);
			printf("%lld ",sum(1,1,n,1,n));
		}
		putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
