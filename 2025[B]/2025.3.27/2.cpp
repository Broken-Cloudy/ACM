#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,i,a[500009],n,b[500009];
int tree[4000009],ANS,ans,mini;
void change(ll node,ll start,ll end,ll X,ll k){
	if(end<X||start>X)return;//加速操作!!!
	else if(start>=X&&end<=X){
		tree[node]+=k;
		return;//记得return 
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,X,k);
		change(you,mid+1,end,X,k);
		tree[node]=tree[zuo]+tree[you];
	}
}
ll sum(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return 0LL;//加速操作!!!
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
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+1+n);ANS=1;mini=1e9+7;
		int bcnt=unique(b+1,b+1+n)-(b+1);
		for(i=1;i<=n;i++){
			mini=min(a[i],mini);
			int l=lower_bound(b+1,b+1+n,mini)-b;
			int r=lower_bound(b+1,b+1+n,a[i])-b;
			change(1,1,bcnt,r,1);
			ans=sum(1,1,bcnt,l+1,r-1);
			ANS=max(ANS,ans+1);
		}
		printf("%lld\n",ANS);
		for(i=1;i<=8*n;i++)tree[i]=0,b[i/8]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
