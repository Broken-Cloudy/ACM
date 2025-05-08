#include<bits/stdc++.h>
#define int long long
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
#define vc(x) tree[x].val
using namespace std;
struct nod{
	int ch[2];//保存左右子树 
	int val;//这里保存值 
};
nod tree[80000009];
int hisv,op,ans;
int T,n,m,q,i,X,K,a[1000009],cnt,root[1000009];//root版本 
int build(int l,int r){//建立空树的编号 
	int rt=++cnt;//子树编号 
	if(l!=r){
		int mid=(l+r)/2;
		lc(rt)=build(l,mid);//建立左子树中所有编号 
		rc(rt)=build(mid+1,r);//建立右子树中所有编号 
	}
	else vc(rt)=a[l];
	return rt;
}
int change(int pre,int l,int r,int x,int k){//pre先前版本的树 
	int rt=++cnt;//子树编号 
	lc(rt)=lc(pre);rc(rt)=rc(pre);//建立新树 
	if(l!=r){
		int mid=(l+r)/2;
		//根据旧树，建立新树
		//lc(pre)-->lc(rt) rc(pre)-->rc(rt)
		//与原来不同的是，只选择那个值域内建树，极大地节约了空间 
		if(x<=mid)lc(rt)=change(lc(pre),l,mid,x,k); 
		else rc(rt)=change(rc(pre),mid+1,r,x,k); 
	}
	else vc(rt)=k;
	return rt;
}
int query(int node,int l,int r,int x){
	if(l==r)return vc(node);
	int mid=(l+r)/2;
	if(x<=mid)return query(lc(node),l,mid,x);
	else return query(rc(node),mid+1,r,x);
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	root[0]=build(1,n);
	for(int o=1;o<=q;o++){
		scanf("%lld%lld",&hisv,&op);
		if(op==1){//change
			scanf("%lld%lld",&X,&K);
			root[o]=change(root[hisv],1,n,X,K);
		}
		else{//query
			scanf("%lld",&X);
			ans=query(root[hisv],1,n,X);
			printf("%lld\n",ans);
			root[o]=root[hisv];
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
