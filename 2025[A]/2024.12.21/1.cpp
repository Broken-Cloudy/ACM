#include<bits/stdc++.h>
#define int unsigned long long
#define ll unsigned long long
using namespace std;
const int MAXX=2e5+9;
const int INF=1e20+9;
int T,n,a[MAXX],b[MAXX],i,l,r,dd,kk,mini,ans;
int tree_min[8*MAXX],tree[8*MAXX],tag[8*MAXX];
void build_min(ll node,ll start,ll end){//Ҫ�¸�,�Ƚ��� 
	if(start==end){
		tree_min[node]=b[start];//��return a[end] 
	}
	else{//node�ǵ�ǰ�������е����� 
		ll mid=(start+end)/2;
		ll zuo=2*node;//ֱ�ӷ��������� 
		ll you=2*node+1;//ֱ�ӷ��������� 
		build_min(zuo,start,mid);
		build_min(you,mid+1,end);
		tree_min[node]=min(tree_min[zuo],tree_min[you]);
	}
}
ll sum_min(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return INF;//���ٲ���!!!
	else if(start>=L&&end<=R)return tree_min[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum_min(zuo,start,mid,L,R);
		ll y=sum_min(you,mid+1,end,L,R);
		return min(x,y);
	}
}
void build(ll node,ll start,ll end){//Ҫ�¸�,�Ƚ��� 
	if(start==end){
		tree[node]=1;//��return a[end] 
	}
	else{//node�ǵ�ǰ�������е����� 
		ll mid=(start+end)/2;
		ll zuo=2*node;//ֱ�ӷ��������� 
		ll you=2*node+1;//ֱ�ӷ��������� 
		build(zuo,start,mid);
		build(you,mid+1,end);
	}
}
void add_tag(ll node,ll start,ll end,ll k){//���˱�� 
	if(tag[node]>INF/k)tag[node]=INF;
	else tag[node]*=k;
	if(tree[node]>INF/k)tree[node]=INF;
	else tree[node]*=k;
	return;
}
void pushdown(ll node,ll start,ll end){//ֻ��ִ��һ�� 
	if(tag[node]==1)return;//û�б�ǣ�����Ҫ����
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag[node];
		add_tag(zuo,start,mid,t);//����´�(��ǲ�����ȥ���������´�) 
		add_tag(you,mid+1,end,t);//����´�(��ǲ�����ȥ���������´�) 
		tag[node]=1;//������ 
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
	}
}
//L��Ŀ���� R��Ŀ����[L,R]
//start�ǵ�ǰ���ڲ�ѯ����ʼ�㣬end�ǵ�ǰ���ڲ�ѯ�Ľ�����
//��ǰ���ڲ�ѯ[start,end] 
ll sum(ll node,ll start,ll end,ll L,ll R){
	pushdown(node,start,end);//NlogN�� 
	if(end<L||start>R)return 1LL;//���ٲ���!!!
	else if(start>=L&&end<=R)return tree[node];
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum(zuo,start,mid,L,R);
		ll y=sum(you,mid+1,end,L,R);
		if(x>INF/y)return INF;
		else return x*y;
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%llu",&n);ans=0;
		for(i=1;i<=8*n;i++){
			tree[i]=tree_min[i]=0;tag[i]=1;
		}
		for(i=1;i<=n;i++)scanf("%llu",&a[i]);
		for(i=1;i<=n;i++)scanf("%llu",&b[i]);
		build_min(1,1,n);build(1,1,n);
		l=1;r=n;
		while(l<=r){
			dd=sum(1,1,n,l,l);
			while(l<=r&&dd>=a[l]){
				l++;dd=sum(1,1,n,l,l);
			}
			kk=sum(1,1,n,r,r);
			while(l<=r&&kk>=a[r]){
				r--;kk=sum(1,1,n,r,r);
			}
			if(l>r)break;
			mini=sum_min(1,1,n,l,r);
			change(1,1,n,l,r,mini);ans++;
		}
		printf("%llu\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
