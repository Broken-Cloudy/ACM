#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct nod{
	int jud,i,j;
};
nod tree[2000009];
ll a[2000009],ju[2000009],i,n,m,op,x,y,k,T,q,l,r;
ll tag[2000009];//Lazy tag 
void build(ll node,ll start,ll end){//Ҫ�¸�,�Ƚ��� 
	if(start==end){
		tree[node].jud=ju[start];//��return a[end] 
		tree[node].i=start;tree[node].j=start+1;
	}
	else{//node�ǵ�ǰ�������е����� 
		ll mid=(start+end)/2;
		ll zuo=2*node;//ֱ�ӷ��������� 
		ll you=2*node+1;//ֱ�ӷ��������� 
		build(zuo,start,mid);
		build(you,mid+1,end);
		if(tree[zuo].jud==1){
			tree[node].jud=1;
			tree[node].i=tree[zuo].i;
			tree[node].j=tree[zuo].j;
		}
		else if(tree[you].jud==1){
			tree[node].jud=1;
			tree[node].i=tree[you].i;
			tree[node].j=tree[you].j;
		}
		else tree[node].jud=0;
	}
}
//L��Ŀ���� R��Ŀ����[L,R]
//start�ǵ�ǰ���ڲ�ѯ����ʼ�㣬end�ǵ�ǰ���ڲ�ѯ�Ľ�����
//��ǰ���ڲ�ѯ[start,end] 
nod sum(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R){
		nod cc;
		cc.i=0;cc.j=0;cc.jud=0;
		return cc;//���ٲ���!!!
	}
	else if(start>=L&&end<=R){
		nod r;
		r.jud=tree[node].jud;
		r.i=tree[node].i;
		r.j=tree[node].j;
		return r; 
	}
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		nod x=sum(zuo,start,mid,L,R);
		nod y=sum(you,mid+1,end,L,R);
		if(x.jud==1){
			return x;
		}
		else if(y.jud==1){
			return y;
		}
		else{
			nod cc;
			cc.i=0;cc.j=0;cc.jud=0;
			return cc;
		}
	}
}
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		//ju������n-1��Ԫ�� 
		for(i=1;i<n;i++){
			if(a[i]!=a[i+1])ju[i]=1;
			else ju[i]=0;
		}
		build(1,1,n-1);
		scanf("%lld",&q);
		for(i=1;i<=q;i++){
			scanf("%lld%lld",&l,&r);
			nod ans=sum(1,1,n-1,l,r-1);
			if(ans.jud==0){
				printf("-1 -1\n");
			}
			else{
				printf("%d %d\n",ans.i,ans.j);
			}
		}
		printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
