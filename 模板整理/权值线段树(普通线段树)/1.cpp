#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[4000009],tree[4000009],i,n,m,op,x,y,k;
ll tag[4000009];//Lazy tag 
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
void add_tag(ll node,ll start,ll end,ll k){//���˱�� 
	tag[node]+=k;
	tree[node]+=(end-start+1)*k;//�Ȱѱ�������ˣ�����Ĳ����Ȳ��ӣ������� 
	return;
}
void pushdown(ll node,ll start,ll end){//ֻ��ִ��һ�� 
	if(tag[node]==0)return;//û�б�ǣ�����Ҫ����
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag[node];
		add_tag(zuo,start,mid,t);//����´�(��ǲ�����ȥ���������´�) 
		add_tag(you,mid+1,end,t);//����´�(��ǲ�����ȥ���������´�) 
		tag[node]=0;//������ 
	} 
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
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
ll sum(ll node,ll start,ll end,ll L,ll R){
	pushdown(node,start,end);//NlogN�� 
	if(end<L||start>R)return 0;//���ٲ���!!!
	else if(start>=L&&end<=R)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum(zuo,start,mid,L,R);
		ll y=sum(you,mid+1,end,L,R);
		return x+y;
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	build(1,1,n);
	for(i=1;i<=m;i++){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			change(1,1,n,x,y,k);
		}
		else{
			scanf("%lld%lld",&x,&y);
			ll ans=sum(1,1,n,x,y);
			printf("%lld\n",ans);//1�Ǹ���㣬����sum[1,n] 
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
