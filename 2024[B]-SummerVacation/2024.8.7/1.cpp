#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,n,a[200009],m,x,y,i;
int tag[800009],tree[800009];
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
void add_tag(ll node,ll start,ll end){//���˱�� 
	tag[node]=1;
	tree[node]=(end-start+1);//�Ȱѱ�������ˣ�����Ĳ����Ȳ��ӣ������� 
	return;
}
void pushdown(ll node,ll start,ll end){//ֻ��ִ��һ�� 
	if(tag[node]==0)return;//û�б�ǣ�����Ҫ����
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		add_tag(zuo,start,mid);//����´�(��ǲ�����ȥ���������´�) 
		add_tag(you,mid+1,end);//����´�(��ǲ�����ȥ���������´�) 
		tag[node]=0;//������ 
	} 
}
void change(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return;//���ٲ���!!!
	else if(start>=L&&end<=R){
		add_tag(node,start,end);
		return;//�ǵ�return 
	} 
	else{
		pushdown(node,start,end);//��ֵ��ʱ��ҲҪ�´���ϸ����������ܻ�Ӱ���� 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R);
		change(you,mid+1,end,L,R);
		tree[node]=tree[zuo]+tree[you];
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
		return x+y;
	}
}
int ans1,ans2,ans3,sum1,sum2;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(i=0;i<=n;i++)a[i]=0;
		build(1,1,n);
		for(i=1;i<=m;i++){
			scanf("%lld%lld",&x,&y);
			ans1=sum(1,1,n,1,x);ans2=sum(1,1,n,y,n);ans3=sum(1,1,n,x,y);
			sum1=min((x-1+1)+(n-y+1)-(ans1+ans2),(x-1+1)+(n-y+1)-1);
			sum2=min((y-x+1)-ans3,(y-x+1)-1);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
