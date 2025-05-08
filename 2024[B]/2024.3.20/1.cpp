#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e18+7;
ll a[7000009],tree[7000009],i,n,m,op,x,y,k;
ll tag[7000009],tag2[7000009];//Lazy tag 
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
		tree[node]=max(tree[zuo],tree[you]);
	}
}
void add_tag(ll node,ll start,ll end,ll k){//���˱�� 
	if(tag2[node]==inf){
		tag[node]+=k;
		tree[node]+=k;
	}
	else{
		tag2[node]+=k;
		tree[node]+=k;//�Ȱѱ�������ˣ�����Ĳ����Ȳ��ӣ������� 
	}
	return;
}
void change_tag(ll node,ll start,ll end,ll k){//���˱�� 
	tag2[node]=k;
	tag[node]=0;//�ӷ������ 
	tree[node]=k;
	return;
}
void pushdown(ll node,ll start,ll end){//ֻ��ִ��һ�� 
	if(tag[node]==0&&tag2[node]==inf)return;//û�б�ǣ�����Ҫ����
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		if(tag[node]!=0){
			ll t=tag[node];
			add_tag(zuo,start,mid,t);//����´�(��ǲ�����ȥ���������´�) 
			add_tag(you,mid+1,end,t);//����´�(��ǲ�����ȥ���������´�) 
			tag[node]=0;//������ 
			tag2[node]=inf;
		}
		else if(tag2[node]!=inf){
			ll t2=tag2[node];
			change_tag(zuo,start,mid,t2);//����´�(��ǲ�����ȥ���������´�) 
			change_tag(you,mid+1,end,t2);//����´�(��ǲ�����ȥ���������´�) 
			tag[node]=0;//������ 
			tag2[node]=inf;
		}
	} 
}
void make_change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//���ٲ���!!!
	else if(start>=L&&end<=R){
		change_tag(node,start,end,k);
		return;//�ǵ�return 
	} 
	else{
		pushdown(node,start,end);//��ֵ��ʱ��ҲҪ�´���ϸ����������ܻ�Ӱ���� 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		make_change(zuo,start,mid,L,R,k);
		make_change(you,mid+1,end,L,R,k);
		tree[node]=max(tree[zuo],tree[you]);
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
		tree[node]=max(tree[zuo],tree[you]);
	}
}
//L��Ŀ���� R��Ŀ����[L,R]
//start�ǵ�ǰ���ڲ�ѯ����ʼ�㣬end�ǵ�ǰ���ڲ�ѯ�Ľ�����
//��ǰ���ڲ�ѯ[start,end] 
ll getmax(ll node,ll start,ll end,ll L,ll R){
	pushdown(node,start,end);//NlogN�� 
	if(end<L||start>R)return -inf;//���ٲ���!!!
	else if(start>=L&&end<=R)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=getmax(zuo,start,mid,L,R);
		ll y=getmax(you,mid+1,end,L,R);
		return max(x,y);
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=7000000;i++)tree[i]=inf;
	for(i=1;i<=7000000;i++)tag2[i]=inf;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	build(1,1,n);
	for(i=1;i<=m;i++){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			make_change(1,1,n,x,y,k);
		}
		else if(op==2){
			scanf("%lld%lld%lld",&x,&y,&k);
			change(1,1,n,x,y,k);
		}
		else{
			scanf("%lld%lld",&x,&y);
			ll ans=getmax(1,1,n,x,y);
			printf("%lld\n",ans);//1�Ǹ���㣬����sum[1,n] 
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
