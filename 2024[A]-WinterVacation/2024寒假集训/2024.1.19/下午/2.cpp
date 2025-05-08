#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[4000009],tree[4000009],i,n,m,op,x,y,k,q;
ll tag[4000009],tag2[4000009];//Lazy tag 
void build(ll node,ll start,ll end){//Ҫ�¸�,�Ƚ��� 
	if(start==end){
		tree[node]=a[start]%m;//��return a[end] 
	}
	else{//node�ǵ�ǰ�������е����� 
		ll mid=(start+end)/2;
		ll zuo=2*node;//ֱ�ӷ��������� 
		ll you=2*node+1;//ֱ�ӷ��������� 
		build(zuo,start,mid);
		build(you,mid+1,end);
		tree[node]=tree[zuo]%m+tree[you]%m;
	}
}
void add_tag(ll node,ll start,ll end,ll k){//���˱�� 
	tag[node]+=k;
	tree[node]+=(end-start+1)*k;//�Ȱѱ�������ˣ�����Ĳ����Ȳ��ӣ������� 
	tree[node]%=m;
	return;
}
void multi_tag(ll node,ll start,ll end,ll k){
	tag2[node]*=k;
	tag2[node]%=m;//
	tag[node]*=k;//�ӷ�Ҳ�ᱻ���� 
	tag[node]%=m;//
	tree[node]*=k;//�Ȱѱ�������ˣ�����Ĳ����Ȳ��ˣ������� 
	tree[node]%=m;// 
	return;
}
void pushdown(ll node,ll start,ll end){//ֻ��ִ��һ�� 
	if(tag[node]==0&&tag2[node]==1)return;//û�б�ǣ�����Ҫ����
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag[node];//�ӷ� 
		ll d=tag2[node];//�˷� 
		multi_tag(zuo,start,mid,d);//�Ѿ�Ĭ�ϼӷ��ں��� 
		add_tag(zuo,start,mid,t);//����´�(��ǲ�����ȥ���������´�) 
		multi_tag(you,mid+1,end,d);
		add_tag(you,mid+1,end,t);//����´�(��ǲ�����ȥ���������´�) 
		tag[node]=0;//������ 
		tag2[node]=1; 
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
		tree[node]=tree[zuo]%m+tree[you]%m;
		tree[node]%=m;
	}
}
void change2(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//���ٲ���!!!
	else if(start>=L&&end<=R){
		multi_tag(node,start,end,k);
		return;//�ǵ�return 
	} 
	else{
		pushdown(node,start,end);//ϸ����������ܻ�Ӱ���� 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change2(zuo,start,mid,L,R,k);
		change2(you,mid+1,end,L,R,k);
		tree[node]=tree[zuo]%m+tree[you]%m;
		tree[node]%=m;
	}
}
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
		x%=m;y%=m;
		return (x+y)%m;
	}
}
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>q>>m;
	for(i=1;i<=400000;i++)tag2[i]=1;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]%=m;
	}
	build(1,1,n);
	for(i=1;i<=q;i++){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			change2(1,1,n,x,y,k);
		}
		else if(op==2){
			scanf("%lld%lld%lld",&x,&y,&k);
			change(1,1,n,x,y,k);
		}
		else{
			scanf("%lld%lld",&x,&y);
			ll ans=sum(1,1,n,x,y);
			printf("%lld\n",ans%m);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
