#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll a[4000009],tree[4000009],i,n,m,op,x,y,k,q,bh[100009],j,num;
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
		tree[node]=min(tree[zuo],tree[you]);
	}
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//���ٲ���!!!
	else if(start>=L&&end<=R){
		tree[node]=k;
		return;//�ǵ�return 
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k);
		change(you,mid+1,end,L,R,k);
		tree[node]=min(tree[zuo],tree[you]);
	}
}
//L��Ŀ���� R��Ŀ����[L,R]
//start�ǵ�ǰ���ڲ�ѯ����ʼ�㣬end�ǵ�ǰ���ڲ�ѯ�Ľ�����
//��ǰ���ڲ�ѯ[start,end] 
ll sum(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return 1000000009LL;//���ٲ���!!!
	else if(start>=L&&end<=R)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum(zuo,start,mid,L,R);
		ll y=sum(you,mid+1,end,L,R);
		return min(x,y);
	}
}
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&m);num+=m;
		bh[i]=bh[i-1]+m;
		for(j=1;j<=m;j++){
			scanf("%lld",&a[bh[i-1]+j]);
		}
	} 
	for(i=1;i<=8*num;i++)tree[i]=1000000009LL;
	build(1,1,num);
	cin>>q;
	while(q--){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			int BH=bh[x-1]+y;
			change(1,1,num,BH,BH,k);
		}
		else{
			scanf("%lld",&x);
			int BH=bh[x];
			ll ans=sum(1,1,num,1,BH);
			printf("%lld\n",ans);//1�Ǹ���㣬����sum[1,n] 
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
