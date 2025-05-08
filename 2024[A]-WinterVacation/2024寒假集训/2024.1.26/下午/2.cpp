#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[1000009],i;
ll op,x,y,k,d,p;
struct nod{
	ll K,D;
};
nod tree[1000009];//Lazy tag 
void add_tag(ll node,ll start,ll end,ll k,ll d){//���˱�� 
	tree[node].K+=k;
	tree[node].D+=d;
	return;
}
void pushdown(ll node,ll start,ll end){//ֻ��ִ��һ�� 
	if(tree[node].D==0&&tree[node].K==0)return;//û�б�ǣ�����Ҫ����
	if(start==end)return;
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll k=tree[node].K;
		ll d=tree[node].D;
		add_tag(zuo,start,mid,k,d);//����´�(��ǲ�����ȥ���������´�) 
		add_tag(you,mid+1,end,k+(mid+1-start)*d,d);//����´�(��ǲ�����ȥ���������´�) 
		tree[node].D=0;//������ 
		tree[node].K=0;
	} 
}
void change(ll node,ll start,ll end,ll L,ll R,ll k,ll d){
	if(end<L||start>R)return;//���ٲ���!!!
	else if(start>=L&&end<=R){
		add_tag(node,start,end,k+(start-L)*d,d);
		return;//�ǵ�return 
	} 
	else{
		pushdown(node,start,end);//��ֵ��ʱ��ҲҪ�´���ϸ����������ܻ�Ӱ���� 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k,d);
		change(you,mid+1,end,L,R,k,d);
	}
}
ll find(ll node,ll start,ll end,ll P){
	pushdown(node,start,end);//NlogN�� 
	if(end<P||start>P)return 0;//���ٲ���!!!
	else if(start==end&&start==P)return tree[node].K; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=find(zuo,start,mid,P);
		ll y=find(you,mid+1,end,P);
		return x+y;
	}
}
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld%lld%lld",&x,&y,&k,&d);
			change(1,1,n,x,y,k,d);
		}
		else{
			scanf("%lld",&p);
			printf("%lld\n",a[p]+find(1,1,n,p));
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
