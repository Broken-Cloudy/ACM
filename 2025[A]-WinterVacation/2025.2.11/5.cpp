#include<bits/stdc++.h>
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
#define sc(x) tree[x].s
using namespace std;
struct nod{
	int ch[2];//保存左右子树 
	int s;//该树节点值域的数字的个数 
};
nod tree[4000009];
int t,T,n,m,q,i,R,L,K,a[100009],b[100009],cnt,root[100009],now,C,ANS;//root版本 
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
void query(int u,int v,int l,int r,int now){
	int x=sc(lc(v))-sc(lc(u));
	if(l==r)return;
	int mid=(l+r)/2;
	if(b[mid]>=now){
		query(lc(u),lc(v),l,mid,now);//说明左子树的节点个数达到k个,不行的话就只能搜右子树了 
	}
	else{
		query(rc(u),rc(v),mid+1,r,now);//千万千万别忘记减去x 
		K+=x;
	}
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>T;
	while(T--){
		cin>>n>>q;cnt=0;
		for(i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
		sort(b+1,b+1+n);
		m=unique(b+1,b+1+n)-(b+1);//离散化 
		root[0]=build(1,m);
		for(i=1;i<=n;i++){
			int d=lower_bound(b+1,b+1+m,a[i])-b;
			root[i]=insert(root[i-1],1,m,d);//d表示a[i]所在的b的位置 
		}
		while(q--){
			cin>>L>>R>>C;now=a[C];K=1;
			int d=lower_bound(b+1,b+1+m,a[C])-b;
			query(root[L-1],root[R],1,m,now);
			ANS=L+(K-1);
			cout<<ANS<<'\n';
		}
	}
	cout.flush();
	fclose(stdin);fclose(stdout);
	return 0;
}
