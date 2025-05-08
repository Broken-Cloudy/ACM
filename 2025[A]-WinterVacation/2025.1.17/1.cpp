#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
struct nod{//g(x)=ai+i;f(x)=ai-i;
	int max,min,cha;
}treeg[1600009],treef[1600009],ansf,ansg;
int T,a[200009],Q,n,i,f[200009],g[200009],ANS,p,x;
inline void build(ll node,ll start,ll end){//要致富,先建树 
	if(start==end){
		treef[node].max=f[start];
		treef[node].min=f[start];
		treef[node].cha=0;
		treeg[node].max=g[start];
		treeg[node].min=g[start];
		treeg[node].cha=0;
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build(zuo,start,mid);
		build(you,mid+1,end);
		treeg[node].max=max(treeg[zuo].max,treeg[you].max);
		treeg[node].min=min(treeg[zuo].min,treeg[you].min);
		treeg[node].cha=max(treeg[zuo].cha,treeg[you].cha);
		treeg[node].cha=max(treeg[node].cha,treeg[zuo].max-treeg[you].min);
		treef[node].max=max(treef[zuo].max,treef[you].max);
		treef[node].min=min(treef[zuo].min,treef[you].min);
		treef[node].cha=max(treef[zuo].cha,treef[you].cha);
		treef[node].cha=max(treef[node].cha,treef[you].max-treef[zuo].min);
	}
}
inline nod sumf(ll node,ll start,ll end,ll L,ll R){
	nod z;z.max=0;z.min=0;z.cha=0;
	if(end<L||start>R)return z;//加速操作!!!
	else if(start>=L&&end<=R)return treef[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		nod x=sumf(zuo,start,mid,L,R);
		nod y=sumf(you,mid+1,end,L,R);
		z.max=max(x.max,y.max);
		z.min=min(x.min,y.min);
		z.cha=max(x.cha,y.cha);
		z.cha=max(z.cha,y.max-x.min);
		return z;
	}
}
inline void changef(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		treef[node].max=f[start];
		treef[node].min=f[start];
		treef[node].cha=0;
		return;//记得return 
	}
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		changef(zuo,start,mid,L,R);
		changef(you,mid+1,end,L,R);
		treef[node].max=max(treef[zuo].max,treef[you].max);
		treef[node].min=min(treef[zuo].min,treef[you].min);
		treef[node].cha=max(treef[zuo].cha,treef[you].cha);
		treef[node].cha=max(treef[node].cha,treef[you].max-treef[zuo].min);
	}
}
inline void changeg(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		treeg[node].max=g[start];
		treeg[node].min=g[start];
		treeg[node].cha=0;
		return;//记得return 
	}
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		changeg(zuo,start,mid,L,R);
		changeg(you,mid+1,end,L,R);
		treeg[node].max=max(treeg[zuo].max,treeg[you].max);
		treeg[node].min=min(treeg[zuo].min,treeg[you].min);
		treeg[node].cha=max(treeg[zuo].cha,treeg[you].cha);
		treeg[node].cha=max(treeg[node].cha,treeg[zuo].max-treeg[you].min);
	}
}
inline nod sumg(ll node,ll start,ll end,ll L,ll R){
	nod z;z.max=0;z.min=0;z.cha=0;
	if(end<L||start>R)return z;//加速操作!!!
	else if(start>=L&&end<=R)return treeg[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		nod x=sumg(zuo,start,mid,L,R);
		nod y=sumg(you,mid+1,end,L,R);
		z.max=max(x.max,y.max);
		z.min=min(x.min,y.min);
		z.cha=max(x.cha,y.cha);
		z.cha=max(z.cha,x.max-y.min);
		return z;
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&Q);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			f[i]=a[i]-i;g[i]=a[i]+i;
		}
		build(1,1,n);
		ansf=sumf(1,1,n,1,n);ansg=sumg(1,1,n,1,n);
		ANS=max(ansf.cha,ansg.cha);printf("%lld\n",ANS);
		while(Q--){
			scanf("%lld%lld",&p,&x);
			a[p]=x;f[p]=a[p]-p;g[p]=a[p]+p;
			changef(1,1,n,p,p);changeg(1,1,n,p,p);
			ansf=sumf(1,1,n,1,n);ansg=sumg(1,1,n,1,n);
			ANS=max(ansf.cha,ansg.cha);printf("%lld\n",ANS);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
