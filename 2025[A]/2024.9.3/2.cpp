#include<bits/stdc++.h>
#define int long long
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
#define vc(x) tree[x].val
using namespace std;
struct nod{
	int ch[2];//������������ 
	int val;//���ﱣ��ֵ 
};
nod tree[80000009];
int hisv,op,ans;
int T,n,m,q,i,X,K,a[1000009],cnt,root[1000009];//root�汾 
int build(int l,int r){//���������ı�� 
	int rt=++cnt;//������� 
	if(l!=r){
		int mid=(l+r)/2;
		lc(rt)=build(l,mid);//���������������б�� 
		rc(rt)=build(mid+1,r);//���������������б�� 
	}
	else vc(rt)=a[l];
	return rt;
}
int change(int pre,int l,int r,int x,int k){//pre��ǰ�汾���� 
	int rt=++cnt;//������� 
	lc(rt)=lc(pre);rc(rt)=rc(pre);//�������� 
	if(l!=r){
		int mid=(l+r)/2;
		//���ݾ�������������
		//lc(pre)-->lc(rt) rc(pre)-->rc(rt)
		//��ԭ����ͬ���ǣ�ֻѡ���Ǹ�ֵ���ڽ���������ؽ�Լ�˿ռ� 
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
