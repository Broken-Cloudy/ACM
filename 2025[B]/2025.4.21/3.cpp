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
nod tree[3200009];
int T,n,i,m,k,R,L,K,a[200009],b[200009],cnt,root[200009],FF,l,r,abc;//root�汾 
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
int t,d;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);FF=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]),b[i]=a[i];
		sort(b+1,b+1+n);
		m=unique(b+1,b+1+n)-(b+1);//��ɢ�� 
		root[0]=build(1,m);
		for(i=1;i<=n;i++){
			d=lower_bound(b+1,b+1+m,a[i])-b;
			root[i]=insert(root[i-1],1,m,d);//d��ʾa[i]���ڵ�b��λ�� 
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
