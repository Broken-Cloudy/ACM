#include<bits/stdc++.h>
#define int long long
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
#define sc(x) tree[x].s
using namespace std;
struct nod{
	int ch[2];//保存左右子树 
	int s;//该树节点值域的数字的个数 
};
nod tree[8000009];
string s[10009];
int T,n,m,bn,q,add[10009],i,R,L,K,a[200009],b[200009],cnt,root[200009];//root版本 
int build(int l,int r){//建立空树的编号 
	int rt=++cnt;//子树编号 
	sc(rt)=0;//当前值域内数字的个数为0 
	if(l!=r){
		int mid=(l+r)/2;
		lc(rt)=build(l,mid);//建立左子树中所有编号 
		rc(rt)=build(mid+1,r);//建立右子树中所有编号 
	}
	return rt;
}
int insert(int pre,int l,int r,int x){//pre先前版本的树 
	int rt=++cnt;//子树编号 
	lc(rt)=lc(pre);rc(rt)=rc(pre);//建立新树 
	sc(rt)=sc(pre)+1;//当前值域内数字的个数+1
	if(l!=r){
		int mid=(l+r)/2;
		//根据旧树，建立新树
		//lc(pre)-->lc(rt) rc(pre)-->rc(rt)
		//与原来不同的是，只选择那个值域内建树，极大地节约了空间 
		if(x<=mid)lc(rt)=insert(lc(pre),l,mid,x); 
		else rc(rt)=insert(rc(pre),mid+1,r,x); 
	}
	return rt;
}
int query(int u,int v,int l,int r,int k){
	if(l==r)return l;
	int x=sc(lc(v))-sc(lc(u));//[L,R]这个是前缀和思想，就是第R个数--第(L-1)个数 
	int mid=(l+r)/2;
	if(x>=k)return query(lc(u),lc(v),l,mid,k);//说明左子树的节点个数达到k个,不行的话就只能搜右子树了 
	else return query(rc(u),rc(v),mid+1,r,k-x);//千万千万别忘记减去x 
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;bn=n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]),b[i]=a[i];
	cin>>q;
	for(i=1;i<=q;i++){
		cin>>s[i];
		if(s[i]=="add"){
			scanf("%lld",&add[i]);
			b[++bn]=add[i];
		}
	}
	sort(b+1,b+1+bn);
	m=unique(b+1,b+1+bn)-(b+1);//离散化 
	root[0]=build(1,m);
	for(i=1;i<=n;i++){
		int d=lower_bound(b+1,b+1+m,a[i])-b;
		root[i]=insert(root[i-1],1,m,d);//d表示a[i]所在的b的位置 
	}
	bn=n;
	for(i=1;i<=q;i++){
		if(s[i]=="add"){
			bn++;
			int d=lower_bound(b+1,b+1+m,add[i])-b;
			root[bn]=insert(root[bn-1],1,m,d);//d表示a[i]所在的b的位置 
		}
		else{
			int t=query(root[0],root[bn],1,m,(bn+1)/2);//查询版本L--R 
			printf("%lld\n",b[t]);//查询出来的是那个时候的第k小值 
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
