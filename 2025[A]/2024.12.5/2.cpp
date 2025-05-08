#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int MAXX=2e5+9;
int T,n,q,i,tree[8*MAXX],a[MAXX],xx,x,y,b[MAXX],ans;
void GCD(int a,int b){
	if(b==0){
		xx=a;return;
	}
	else GCD(b,a%b);
}
int gcd(int a,int b){
	GCD(a,b);
	return xx;
}
void build(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		tree[node]=a[start];//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build(zuo,start,mid);
		build(you,mid+1,end);
		tree[node]=gcd(tree[zuo],tree[you]);
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
		return gcd(x,y);
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&q);
		for(i=1;i<=n;i++)scanf("%lld",&b[i]);
		for(i=1;i<n;i++)a[i]=max(b[i]-b[i+1],b[i+1]-b[i]);
		if(n==1){
			while(q--){
	 			scanf("%lld%lld",&x,&y);
	 			ans=0;
				if(q)printf("%lld ",ans);
				else printf("%lld\n",ans);
			}
			continue;
		}
		build(1,1,n-1);
		while(q--){
			scanf("%lld%lld",&x,&y);
			if(x==y)ans=0;
			else ans=sum(1,1,n-1,x,y-1);
			if(q)printf("%lld ",ans);
			else printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
