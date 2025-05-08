#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,i,n,q,ans,a[200009],f[200009],g[200009],p,x,ans1,ans2,ANS;
map<int,int>M;
int tree1max[1600009],tree1min[1600009],tree2min[1600009],tree2max[1600009];
void build1max(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		tree1max[node]=f[start];//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build1max(zuo,start,mid);
		build1max(you,mid+1,end);
		tree1max[node]=max(tree1max[zuo],tree1max[you]);
	}
}
void build1min(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		tree1min[node]=f[start];//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build1min(zuo,start,mid);
		build1min(you,mid+1,end);
		tree1min[node]=min(tree1min[zuo],tree1min[you]);
	}
}
void build2max(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		tree2max[node]=g[start];//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build2max(zuo,start,mid);
		build2max(you,mid+1,end);
		tree2max[node]=max(tree2max[zuo],tree2max[you]);
	}
}
void build2min(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		tree2min[node]=g[start];//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build2min(zuo,start,mid);
		build2min(you,mid+1,end);
		tree2min[node]=min(tree2min[zuo],tree2min[you]);
	}
}
ll sum1max(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return -999999999LL;//加速操作!!!
	else if(start>=L&&end<=R)return tree1max[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum1max(zuo,start,mid,L,R);
		ll y=sum1max(you,mid+1,end,L,R);
		return max(x,y);
	}
}
ll sum1min(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return 999999999LL;//加速操作!!!
	else if(start>=L&&end<=R)return tree1min[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum1min(zuo,start,mid,L,R);
		ll y=sum1min(you,mid+1,end,L,R);
		return min(x,y);
	}
}
ll sum2max(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return -999999999LL;//加速操作!!!
	else if(start>=L&&end<=R)return tree2max[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum2max(zuo,start,mid,L,R);
		ll y=sum2max(you,mid+1,end,L,R);
		return max(x,y);
	}
}
ll sum2min(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return 999999999LL;//加速操作!!!
	else if(start>=L&&end<=R)return tree2min[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum2min(zuo,start,mid,L,R);
		ll y=sum2min(you,mid+1,end,L,R);
		return min(x,y);
	}
}
void change1max(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		tree1max[node]=k;
		return;//记得return 
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change1max(zuo,start,mid,L,R,k);
		change1max(you,mid+1,end,L,R,k);
		tree1max[node]=max(tree1max[zuo],tree1max[you]);
	}
}
void change1min(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		tree1min[node]=k;
		return;//记得return 
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change1min(zuo,start,mid,L,R,k);
		change1min(you,mid+1,end,L,R,k);
		tree1min[node]=min(tree1min[zuo],tree1min[you]);
	}
}
void change2max(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		tree2max[node]=k;
		return;//记得return 
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change2max(zuo,start,mid,L,R,k);
		change2max(you,mid+1,end,L,R,k);
		tree2max[node]=max(tree2max[zuo],tree2max[you]);
	}
}
void change2min(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		tree2min[node]=k;
		return;//记得return 
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change2min(zuo,start,mid,L,R,k);
		change2min(you,mid+1,end,L,R,k);
		tree2min[node]=min(tree2min[zuo],tree2min[you]);
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&q);ANS=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			f[i]=a[i]-i;
			g[i]=a[i]+i;
		}
		build1min(1,1,n);build1max(1,1,n);
		build2min(1,1,n);build2max(1,1,n);
		for(i=1;i<=n;i++){
			ans1=sum1max(1,1,n,i,n)-sum1min(1,1,n,1,i);
			ans2=sum2max(1,1,n,1,i)-sum2min(1,1,n,i,n);
			ans=max(ans1,ans2);
			if(ans>ANS){
				ANS=ans;M.clear();
				M[i]=1;M[0]++;
			}
			else if(ans==ANS){
				M[i]=1;M[0]++;
			}
		}
		printf("%lld\n",ANS);
		while(q--){
			scanf("%lld%lld",&p,&x);
			a[p]=x;f[p]=x-p;g[p]=x+p;
			change1max(1,1,n,p,p,f[p]);
			change1min(1,1,n,p,p,f[p]);
			change2max(1,1,n,p,p,g[p]);
			change2min(1,1,n,p,p,g[p]);
			ans1=sum1max(1,1,n,p,n)-sum1min(1,1,n,1,p);
			ans2=sum2max(1,1,n,1,p)-sum2min(1,1,n,p,n);
			ans=max(ans1,ans2);
			if(ans>ANS){
				ANS=ans;M.clear();
				M[i]=1;M[0]++;
			}
			else if(ans==ANS){
				if(M[p]==0){
					M[i]=1;M[0]++;
				}
			}
			else{
				if(M[p]==1&&M[0]==1){
					ANS=ans;M.clear();M[i]=1;M[0]++;
				}
			}
			printf("%lld\n",ANS);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
