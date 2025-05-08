#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const ll MAXN=3e6+8;
ll n,m,a[MAXN*4],treea[MAXN*4],i,op,x,y,k,ans;//treea[MAXN*4]����mini[MAXN*4]
ll tag1[MAXN*4];//tag2_min[MAXN*4]
//hismini[MAXN*4]������ǰ��treeb[MAXN*4] 
ll tag2_hismin[MAXN*4],hismini[MAXN*4];
void add_tag(ll node,ll start,ll end,ll k){
	//ԭ����treeaδ�´� ��ֵ���ڸ������ 
	tag2_hismin[node]=min(tag2_hismin[node],tag1[node]+tag2_hismin[node/2]);
	hismini[node]=min(hismini[node],treea[node]+tag2_hismin[node/2]);
	//�´� 
	tag1[node]+=k;
	treea[node]+=k;//��ǰ���ͱ�ʾһ��������Сֵ��ֻ��Ҫ��k 
	return;
}
void pushdown(ll node,ll start,ll end){//ֻ��ִ��һ�� 
	if(tag1[node]==0)return;//û�б�ǣ�����Ҫ����
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag1[node];
		add_tag(zuo,start,mid,t);//����´�(��ǲ�����ȥ���������´�) 
		add_tag(you,mid+1,end,t);//����´�(��ǲ�����ȥ���������´�)
		tag1[node]=0;//������ 
	} 
}
void build_tree(ll node,ll start,ll end){
	if(start==end){
		treea[node]=a[start];
		return;
	}
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		build_tree(zuo,start,mid);
		build_tree(you,mid+1,end);
		treea[node]=min(treea[zuo],treea[you]);//������Сֵ 
	}
}
ll mini(ll node,ll start,ll end,ll L,ll R){//������Сֵ 
	pushdown(node,start,end);
	if(end<L||start>R)return 0;
	else if(end<=R&&start>=L)return treea[node];
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll x=mini(zuo,start,mid,L,R);
		ll y=mini(you,mid+1,end,L,R);
		return min(x,y);
	}
}
ll hism(ll node,ll start,ll end,ll L,ll R){//������Сֵ 
	pushdown(node,start,end);
	if(end<L||start>R)return 0;
	else if(end<=R&&start>=L)return hismini[node];
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll x=hism(zuo,start,mid,L,R);
		ll y=hism(you,mid+1,end,L,R);
		return min(x,y);
	}
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;
	else if(end<=R&&start>=L){
		add_tag(node,start,end,k);
		return;
	}
	else{
		pushdown(node,start,end);
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k);
		change(you,mid+1,end,L,R,k);
		treea[node]=min(treea[zuo],treea[you]);//pushup 
		hismini[node]=min(hismini[zuo],hismini[you]);
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		//cin>>a[i];
		scanf("%lld",&a[i]);
	}
	build_tree(1,1,n);
	memcpy(hismini,treea,sizeof(treea));
	for(i=1;i<=m;i++){
		//cin>>op;
		scanf("%lld",&op);
		if(op==1){//����� 
			//cin>>x>>y>>k;
			scanf("%lld%lld%lld",&x,&y,&k);
			change(1,1,n,x,y,k);
		}
		else if(op==2){
			//cin>>x>>y;
			scanf("%lld%lld",&x,&y);
			ans=mini(1,1,n,x,y);
			printf("%lld\n",ans);
		}
		else{
			//cin>>x>>y;
			scanf("%lld%lld",&x,&y);
			ans=hism(1,1,n,x,y);
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
