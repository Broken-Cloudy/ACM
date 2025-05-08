#include<bits/stdc++.h>
#define int long long
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
#define sc(x) tree[x].s
using namespace std;
struct nod{
	int ch[2];//������������ 
	int s;//�����ڵ�ֵ������ֵĸ��� 
};
nod tree[8000009];
int T,n,m,q,i,R,L,K,a[200009],b[200009],cnt,root[200009];//root�汾 
int build(int l,int r){//���������ı�� 
	int rt=++cnt;//������� 
	sc(rt)=0;//��ǰֵ�������ֵĸ���Ϊ0 
	if(l!=r){
		int mid=(l+r)/2;
		lc(rt)=build(l,mid);//���������������б�� 
		rc(rt)=build(mid+1,r);//���������������б�� 
	}
	return rt;
}
int insert(int pre,int l,int r,int x){//pre��ǰ�汾���� 
	int rt=++cnt;//������� 
	lc(rt)=lc(pre);rc(rt)=rc(pre);//�������� 
	sc(rt)=sc(pre)+1;//��ǰֵ�������ֵĸ���+1
	if(l!=r){
		int mid=(l+r)/2;
		//���ݾ�������������
		//lc(pre)-->lc(rt) rc(pre)-->rc(rt)
		//��ԭ����ͬ���ǣ�ֻѡ���Ǹ�ֵ���ڽ���������ؽ�Լ�˿ռ� 
		if(x<=mid)lc(rt)=insert(lc(pre),l,mid,x); 
		else rc(rt)=insert(rc(pre),mid+1,r,x); 
	}
	return rt;
}
int query(int u,int v,int l,int r,int k){
	if(l==r)return l;
	int x=sc(lc(v))-sc(lc(u));//[L,R]�����ǰ׺��˼�룬���ǵ�R����--��(L-1)���� 
	int mid=(l+r)/2;
	if(x>=k)return query(lc(u),lc(v),l,mid,k);//˵���������Ľڵ�����ﵽk��,���еĻ���ֻ������������ 
	else return query(rc(u),rc(v),mid+1,r,k-x);//ǧ��ǧ������Ǽ�ȥx 
}
signed main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]),b[i]=a[i];
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-(b+1);//��ɢ�� 
	root[0]=build(1,m);
	for(i=1;i<=n;i++){
		int d=lower_bound(b+1,b+1+m,a[i])-b;
		root[i]=insert(root[i-1],1,m,d);//d��ʾa[i]���ڵ�b��λ�� 
	}
	for(i=1;i<=q;i++){
		scanf("%lld%lld",&L,&R);
		int t=query(root[L-1],root[R],1,m,(R-L)/2+1);//��ѯ�汾L--R 
		printf("%lld\n",b[t]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
