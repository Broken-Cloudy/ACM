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
nod tree[3200009];
int T,n,i,m,k,R,L,K,a[200009],b[200009],cnt,root[200009],FF,l,r,abc;//root版本 
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
int t,d;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);FF=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]),b[i]=a[i];
		sort(b+1,b+1+n);
		m=unique(b+1,b+1+n)-(b+1);//离散化 
		root[0]=build(1,m);
		for(i=1;i<=n;i++){
			d=lower_bound(b+1,b+1+m,a[i])-b;
			root[i]=insert(root[i-1],1,m,d);//d表示a[i]所在的b的位置 
		}
		l=n;r=1;
		for(i=1;i<=n-2;i++){
			t=query(root[0],root[i],1,m,(i+1)/2);
			if(b[t]<=k){
				l=i;
				break;
			}
		}
		for(i=n;i>=3;i--){
			t=query(root[i-1],root[n],1,m,(n-i+2)/2);
			if(b[t]<=k){
				r=i;
				break;
			}
		}
		if(r-l>=2)FF=1;abc=0;
		for(i=2;i<=n-1;i++){
			if(a[i]<=k){
				abc=max(1LL,abc+1);
			}
			else{
				abc--;
			}
			if(abc>=0){
				d=query(root[i],root[n],1,m,max(1LL,(n-i+1-(abc))/2));
				if(b[d]<=k)FF=1;
			}
		}abc=0;
		for(i=n-1;i>=2;i--){
			if(a[i]<=k){
				abc=max(1LL,abc+1);
			}
			else{
				abc--;
			}
			if(abc>=0){
				t=query(root[0],root[i-1],1,m,max(1LL,(i-(abc))/2));
				if(b[t]<=k)FF=1;
			}
		}
		for(i=0;i<=n;i++)root[i]=0;cnt=0;
		for(i=0;i<=cnt;i++)tree[i].ch[0]=0,tree[i].ch[1]=0,tree[i].s=0;
		if(FF==1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
