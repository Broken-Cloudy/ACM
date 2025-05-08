#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int P=9712176LL;
deque<int>q;//编号双头栈 
int n,i,j,a[1000009],cnt,k,ANS,ans,b[1000009];
int ci[1000009],di[1000009],c[1000009],d[1000009]; 
int tree[2][8000009];
void pre(){
	int i,t,ji;//这些都是a[]的序号 
	for(i=1;i<=n;i++){
		if(!q.empty())t=q.back();ji=1;
		while(!q.empty()&&a[i]>a[t]){ 
			d[t]=di[t]*(i-t);d[t]%=P;
			ji+=di[t];
			q.pop_back();
			if(!q.empty())t=q.back();
		}
		di[i]=ji;
		q.push_back(i);
	}
	if(!q.empty())t=q.back();
	while(!q.empty()){
		d[t]=di[t]*(i-t);
		q.pop_back();
		if(!q.empty())t=q.back();
	}
	for(i=1;i<=n;i++){
		if(!q.empty())t=q.back();ji=1;
		while(!q.empty()&&a[i]<a[t]){
			c[t]=ci[t]*(i-t);c[t]%=P;
			ji+=ci[t];
			q.pop_back();
			if(!q.empty())t=q.back();
		}
		ci[i]=ji;
		q.push_back(i);
	}
	if(!q.empty())t=q.back();
	while(!q.empty()){
		c[t]=ci[t]*(i-t);
		q.pop_back();
		if(!q.empty())t=q.back();
	}
}
void change(ll node,ll start,ll end,ll X,ll type){
	if(end<X||start>X)return;//加速操作!!!
	else if(start==X&&end==X){
		tree[type][node]=0;
		return;//记得return 
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,X,type);
		change(you,mid+1,end,X,type);
		tree[type][node]=tree[type][zuo]+tree[type][you];
	}
}
void build(ll node,ll start,ll end,ll type){//要致富,先建树 
	if(start==end){
		tree[type][node]=(type==0?d[start]:d[start]*a[start]%P);//0是求d 1是求d*a 
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build(zuo,start,mid,type);
		build(you,mid+1,end,type);
		tree[type][node]=tree[type][zuo]+tree[type][you];
		tree[type][node]%=P;
	}
}
ll sum(ll node,ll start,ll end,ll L,ll R,ll type){
	if(end<L||start>R)return 0;//加速操作!!!
	else if(start>=L&&end<=R)return tree[type][node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum(zuo,start,mid,L,R,type);
		ll y=sum(you,mid+1,end,L,R,type);
		return (x+y)%P;
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]),b[a[i]]=i;
	pre();
	build(1,1,n,0);build(1,1,n,1);
	int dii,dkk,diai,dkak;
	for(i=n;i>=1;i--){
		j=b[i];
		if(j>1&&j<n){
			dii=sum(1,1,n,1,j-1,0);dkk=sum(1,1,n,j+1,n,0);
			diai=sum(1,1,n,1,j-1,1);dkak=sum(1,1,n,j+1,n,1);
			ans=(a[j]*a[j]%P*dii%P*dkk%P+diai*dkak%P)%P;
			ans=(ans+P-a[j]*(diai*dkk%P+dkak*dii%P)%P)%P;
			ans=(ans+P)%P*c[j];ans%=P;
			ANS+=ans;ANS%=P;
		}
		change(1,1,n,j,0);
		change(1,1,n,j,1);
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
