#include<bits/stdc++.h>
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
#define sc(x) tree[x].s
using namespace std;
struct nod{
	int ch[2];//������������ 
	int s;//�����ڵ�ֵ������ֵĸ��� 
};
nod tree[4000009];
int t,T,n,m,q,i,R,L,K,a[100009],b[100009],cnt,root[100009],now,C,ANS;//root�汾 
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
void query(int u,int v,int l,int r,int now){
	int x=sc(lc(v))-sc(lc(u));
	if(l==r)return;
	int mid=(l+r)/2;
	if(b[mid]>=now){
		query(lc(u),lc(v),l,mid,now);//˵���������Ľڵ�����ﵽk��,���еĻ���ֻ������������ 
	}
	else{
		query(rc(u),rc(v),mid+1,r,now);//ǧ��ǧ������Ǽ�ȥx 
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
		m=unique(b+1,b+1+n)-(b+1);//��ɢ�� 
		root[0]=build(1,m);
		for(i=1;i<=n;i++){
			int d=lower_bound(b+1,b+1+m,a[i])-b;
			root[i]=insert(root[i-1],1,m,d);//d��ʾa[i]���ڵ�b��λ�� 
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
