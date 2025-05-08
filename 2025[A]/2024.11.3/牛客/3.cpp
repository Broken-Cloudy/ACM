#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,n,m,op,x,y;
struct nod{
	int L,R;
}Tree[4000009],Tag[4000009];
double tree[4000009],a[4000009],tag[4000009],len,k;
void build2(ll node,ll start,ll end){//Ҫ�¸�,�Ƚ��� 
	if(start==end){
		Tree[node].L=start;//��return a[end] 
		Tree[node].R=end;//��return a[end] 
	}
	else{//node�ǵ�ǰ�������е����� 
		ll mid=(start+end)/2;
		ll zuo=2*node;//ֱ�ӷ��������� 
		ll you=2*node+1;//ֱ�ӷ��������� 
		build2(zuo,start,mid);
		build2(you,mid+1,end);
	}
}
void add_tag2(ll node,ll start,ll end,ll LL,ll RR){//���˱�� 
	Tag[node].L=LL;Tag[node].R=RR;
	Tree[node].L=LL;//�Ȱѱ�������ˣ�����Ĳ����Ȳ��ӣ������� 
	Tree[node].R=RR;
	return;
}
void pushdown2(ll node,ll start,ll end){//ֻ��ִ��һ�� 
	if(Tag[node].L==0&&Tag[node].R==0)return;//û�б�ǣ�����Ҫ����
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		add_tag2(zuo,start,mid,Tag[node].L,Tag[node].R);//����´�(��ǲ�����ȥ���������´�) 
		add_tag2(you,mid+1,end,Tag[node].L,Tag[node].R);//����´�(��ǲ�����ȥ���������´�) 
		Tag[node].L=0;Tag[node].R=0;//������ 
	} 
}
void change2(ll node,ll start,ll end,ll L,ll R,ll LL,ll RR){
	if(end<L||start>R)return;//���ٲ���!!!
	else if(start>=L&&end<=R){
		add_tag2(node,start,end,LL,RR);
		return;//�ǵ�return 
	} 
	else{
		pushdown2(node,start,end);//��ֵ��ʱ��ҲҪ�´���ϸ����������ܻ�Ӱ���� 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change2(zuo,start,mid,L,R,LL,RR);
		change2(you,mid+1,end,L,R,LL,RR);
	}
}
nod sum2(ll node,ll start,ll end,ll L,ll R){
	nod p;p.L=99999999LL;p.R=0;
	pushdown2(node,start,end);//NlogN�� 
	if(end<L||start>R)return p;//���ٲ���!!!
	else if(start>=L&&end<=R)return Tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		nod x=sum2(zuo,start,mid,L,R);
		nod y=sum2(you,mid+1,end,L,R);
		p.L=min(x.L,y.L);p.R=max(x.R,y.R);
		return p;
	}
}
//L��Ŀ���� R��Ŀ����[L,R]
//start�ǵ�ǰ���ڲ�ѯ����ʼ�㣬end�ǵ�ǰ���ڲ�ѯ�Ľ�����
//��ǰ���ڲ�ѯ[start,end] 
void build(ll node,ll start,ll end){//Ҫ�¸�,�Ƚ��� 
	if(start==end){
		tree[node]=a[start];//��return a[end] 
	}
	else{//node�ǵ�ǰ�������е����� 
		ll mid=(start+end)/2;
		ll zuo=2*node;//ֱ�ӷ��������� 
		ll you=2*node+1;//ֱ�ӷ��������� 
		build(zuo,start,mid);
		build(you,mid+1,end);
		tree[node]=tree[zuo]+tree[you];
	}
}
void add_tag(ll node,ll start,ll end,double k){//���˱�� 
	tag[node]=k;
	tree[node]=(end-start+1.0)*k;//�Ȱѱ�������ˣ�����Ĳ����Ȳ��ӣ������� 
	return;
}
void pushdown(ll node,ll start,ll end){//ֻ��ִ��һ�� 
	if(tag[node]==0)return;//û�б�ǣ�����Ҫ����
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		double t=tag[node];
		add_tag(zuo,start,mid,t);//����´�(��ǲ�����ȥ���������´�) 
		add_tag(you,mid+1,end,t);//����´�(��ǲ�����ȥ���������´�) 
		tag[node]=0;//������ 
	} 
}
void change(ll node,ll start,ll end,ll L,ll R,double k){
	if(end<L||start>R)return;//���ٲ���!!!
	else if(start>=L&&end<=R){
		add_tag(node,start,end,k);
		return;//�ǵ�return 
	} 
	else{
		pushdown(node,start,end);//��ֵ��ʱ��ҲҪ�´���ϸ����������ܻ�Ӱ���� 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k);
		change(you,mid+1,end,L,R,k);
		tree[node]=tree[zuo]+tree[you];
	}
}
//L��Ŀ���� R��Ŀ����[L,R]
//start�ǵ�ǰ���ڲ�ѯ����ʼ�㣬end�ǵ�ǰ���ڲ�ѯ�Ľ�����
//��ǰ���ڲ�ѯ[start,end] 
double sum(ll node,ll start,ll end,ll L,ll R){
	pushdown(node,start,end);//NlogN�� 
	if(end<L||start>R)return 0.0;//���ٲ���!!!
	else if(start>=L&&end<=R)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		double x=sum(zuo,start,mid,L,R);
		double y=sum(you,mid+1,end,L,R);
		return x+y;
	}
}
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	} 
	build(1,1,n);build2(1,1,n);
	for(i=1;i<=m;i++){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld",&x,&y);
			nod t1=sum2(1,1,n,x,x);
			nod t2=sum2(1,1,n,y,y);
			len=t2.R-t1.L+1;
			double SUM=sum(1,1,n,t1.L,t2.R);
			k=SUM/len;
			change(1,1,n,t1.L,t2.R,k);
			change2(1,1,n,t1.L,t2.R,t1.L,t2.R);
		}
		else{
			scanf("%lld",&x);
			double ans=sum(1,1,n,x,x);
			printf("%.8lf\n",ans);//1�Ǹ���㣬����sum[1,n] 
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
