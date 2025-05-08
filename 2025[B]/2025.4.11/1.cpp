#include<bits/stdc++.h>
#define ll int
using namespace std;
deque<int>d;
int T,i,n,a[500009],zuo[500009],zuocnt,you[500009],youcnt,t;
int tree[4000009],tag[4000009];
void PRE(){
	zuocnt=youcnt=0;
	for(i=n;i>=1;i--){//����� 
		while(!d.empty()){
			t=d.back();
			if(t>=a[i])d.pop_back();
			else break;
		}
		d.push_back(a[i]);
	}
	while(!d.empty()){//�γɵ����� 
		t=d.front();d.pop_front();
		zuo[++zuocnt]=t;
	}
	for(i=1;i<=n;i++){//����� 
		while(!d.empty()){
			t=d.back();
			if(t<=a[i])d.pop_back();
			else break;
		}
		d.push_back(a[i]);
	}
	while(!d.empty()){//�γɵ����� 
		t=d.front();d.pop_front();
		you[++youcnt]=t;
	}
	for(i=1;i<=8*n;i++)tag[i]=tree[i]=0LL;
}
void add_tag(ll node,ll start,ll end,ll k){//���˱�� 
	tag[node]+=k;
	tree[node]+=k;//�Ȱѱ�������ˣ�����Ĳ����Ȳ��ӣ������� 
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
		tree[node]=max(tree[zuo],tree[you]);
	}
}
ll sum(ll node,ll start,ll end,ll L,ll R){
	pushdown(node,start,end);//NlogN�� 
	if(end<L||start>R)return 0LL;//���ٲ���!!!
	else if(start>=L&&end<=R)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum(zuo,start,mid,L,R);
		ll y=sum(you,mid+1,end,L,R);
		return max(x,y);
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		PRE();
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
