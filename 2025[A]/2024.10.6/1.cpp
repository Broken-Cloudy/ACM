#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,last,n,len,Z[3000009],i,j,tree[24000009],tag[24000009],k;
char cc,a[3000009];
string ss;
int num(char c){return (c-'a');}
void add_tag(ll node,ll start,ll end,ll k){//懒人标记 
	tag[node]+=k;
	tree[node]+=(end-start+1)*k;//先把本层给加了，下面的层数先不加，打个标记 
	return;
}
void pushdown(ll node,ll start,ll end){//只需执行一次 
	if(tag[node]==0)return;//没有标记，不需要考虑
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag[node];
		add_tag(zuo,start,mid,t);//标记下传(标记并不是去除，而是下传) 
		add_tag(you,mid+1,end,t);//标记下传(标记并不是去除，而是下传) 
		tag[node]=0;//标记清空 
	} 
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		add_tag(node,start,end,k);
		return;//记得return 
	} 
	else{
		pushdown(node,start,end);//加值的时候也要下传，细化，否则可能会影响结果 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k);
		change(you,mid+1,end,L,R,k);
		tree[node]=tree[zuo]+tree[you];
	}
}
ll sum(ll node,ll start,ll end,ll L,ll R){
	pushdown(node,start,end);//NlogN次 
	if(end<L||start>R)return 0ll;//加速操作!!!
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
int l,r=0;
void exKMP(int i){//一个一个匹配 
	if(i>=2){
		if(i<=r)Z[i]=min(Z[i-l+1],r-i+1);//在盒内 S[i,r]=S[i-l+1,r-l+1] 
		while(a[1+Z[i]]==a[i+Z[i]])Z[i]++;
		if(i+Z[i]-1>r)l=i,r=i+Z[i]-1;
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>ss;
		if(ss=="add"){
			getchar();cc=getchar();cc=(cc-'a'+last)%26+'a';
			a[++len]=cc;exKMP(len);
		}
		else{
			scanf("%lld",&k);
			k=(k-1+last)%len+1;
			last=sum(1,1,3000000,k,k)+1LL;
			printf("%lld\n",last);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
