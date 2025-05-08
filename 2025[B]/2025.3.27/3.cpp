#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
queue<int>q;
int T,i,a[500009],b[500009],n,vis[1000009],t,kk;
int tree[4000009],tag[4000009],cnt,ANS;
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
ll sum(ll node,ll start,ll end,ll X){
	pushdown(node,start,end);//NlogN�� 
	if(end<X||start>X)return 0LL;//���ٲ���!!!
	else if(start>=X&&end<=X)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum(zuo,start,mid,X);
		ll y=sum(you,mid+1,end,X);
		return x+y;
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		while(!q.empty())q.pop();
		scanf("%lld",&n);ANS=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+1+n);
		cnt=unique(b+1,b+1+n)-(b+1);
		for(i=1;i<=n;i++){
			if(vis[a[i]]==0){
				vis[a[i]]=1;
				t=lower_bound(b+1,b+1+cnt,a[i])-b;
				kk=sum(1,1,cnt,t);
				change(1,1,cnt,t,t,-(kk-1));
				change(1,1,cnt,1,t-1,1);
			}
			else{
				t=lower_bound(b+1,b+1+cnt,a[i])-b;
				change(1,1,cnt,1,t-1,1);
			}
		}
		for(i=1;i<=n;i++){
			t=lower_bound(b+1,b+1+cnt,a[i])-b;
			kk=sum(1,1,cnt,t);
			ANS=max(ANS,kk);
		}
		printf("%lld\n",ANS);
		for(i=1;i<=8*n;i++)tree[i]=tag[i]=0;
		for(i=1;i<=n;i++)vis[a[i]]=0,b[i]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
