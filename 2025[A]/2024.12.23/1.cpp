#include<bits/stdc++.h>
#define int long long
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
#define sc(x) tree[x].s
using namespace std;
int T,n,i,k,L,R,ans;
struct node{
	int a,b;
}r[200009];
bool cmp(node x,node y){
	return x.b<y.b;
}
struct nod{
	int ch[2];//������������ 
	int s;//�����ڵ�ֵ������ֵĸ��� 
};
nod tree[8000009];
int cnt,root[200009],a[200009],b[200009],c[400009],e[200009],ccnt,val;//root�汾 
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
	if(x>=k)return query(lc(u),lc(v),l,mid,k);//˵���������Ľڵ�����ﵽk�� 
	else return query(rc(u),rc(v),mid+1,r,k-x);//���еĻ���ֻ������������ 
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    cin>>T;
    while(T--){
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)scanf("%lld",&r[i].a),c[++ccnt]=r[i].a;
		for(i=1;i<=n;i++)scanf("%lld",&r[i].b),c[++ccnt]=r[i].b;
		sort(r+1,r+1+n,cmp);
		for(i=1;i<=n;i++){//������� 
			a[i]=b[i]=r[i].a;
			e[i]=r[i].b;
		}
		sort(b+1,b+1+n);sort(c+1,c+1+2*n);sort(e+1,e+1+n);
		int m=unique(b+1,b+1+n)-(b+1);//��ɢ�� 
		int C=unique(c+1,c+1+ccnt)-(c+1);//��ɢ�� 
		root[0]=build(1,m);
		for(i=1;i<=n;i++){
			int d=lower_bound(b+1,b+1+m,a[i])-b;
			root[i]=insert(root[i-1],1,m,d);//d��ʾa[i]���ڵ�b��λ�� 
		}
		for(i=1;i<=C;i++){
			L=lower_bound(e+1,e+1+n,c[i])-e;
			R=n;
			if(L>R)break;
			if(k>=(R-L+1)){
				ans=max(ans,c[i]*(R-L+1)); 
			}
			else{
				int t=query(root[L-1],root[R],1,m,k+1);//��ѯ�汾L--R
				if(b[t]<c[i])continue;
				else{
					ans=max(ans,c[i]*(R-L+1));
				}
			}
		}
		printf("%lld\n",ans);ans=0;cnt=0;ccnt=0;
		for(i=0;i<=n;i++)root[i]=a[i]=b[i]=0;
		for(i=0;i<=2*n;i++)c[i]=0;
	}
    fclose(stdin);fclose(stdout);
    return 0;
}
