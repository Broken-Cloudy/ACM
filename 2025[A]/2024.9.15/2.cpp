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
string s[10009];
int T,n,m,bn,q,add[10009],i,R,L,K,a[200009],b[200009],cnt,root[200009];//root�汾 
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
	m=unique(b+1,b+1+bn)-(b+1);//��ɢ�� 
	root[0]=build(1,m);
	for(i=1;i<=n;i++){
		int d=lower_bound(b+1,b+1+m,a[i])-b;
		root[i]=insert(root[i-1],1,m,d);//d��ʾa[i]���ڵ�b��λ�� 
	}
	bn=n;
	for(i=1;i<=q;i++){
		if(s[i]=="add"){
			bn++;
			int d=lower_bound(b+1,b+1+m,add[i])-b;
			root[bn]=insert(root[bn-1],1,m,d);//d��ʾa[i]���ڵ�b��λ�� 
		}
		else{
			int t=query(root[0],root[bn],1,m,(bn+1)/2);//��ѯ�汾L--R 
			printf("%lld\n",b[t]);//��ѯ���������Ǹ�ʱ��ĵ�kСֵ 
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
