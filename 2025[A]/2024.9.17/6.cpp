#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int mod=1e9+7;
int R[200009],C[200009],r[200009],c[200009];
int numr[200009],numc[200009],fac[200009],nfac[200009];
int i,n,q,d1,d2,d3,d4,ans1,ans2,ANS,x,y,tree[2][1600009],m;
void exgcd(int a,int b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;y=t-(a/b)*y;
}
void build(ll node,ll start,ll end,ll type){//要致富,先建树 
	if(start==end){
		tree[type][node]=(type==0?numr[start]:numc[start]);//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ll mid=(start+end)/2;
		ll zuo=2*node;//直接访问左子树 
		ll you=2*node+1;//直接访问右子树 
		build(zuo,start,mid,type);
		build(you,mid+1,end,type);
		tree[type][node]=tree[type][zuo]*tree[type][you];
		tree[type][node]%=mod;
	}
}
ll sum(ll node,ll start,ll end,ll L,ll R,ll type){
	if(end<L||start>R||L>R)return 1;//加速操作!!!
	else if(start>=L&&end<=R)return tree[type][node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum(zuo,start,mid,L,R,type);
		ll y=sum(you,mid+1,end,L,R,type);
		return (x*y)%mod;
	}
}
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	fac[0]=1;nfac[0]=1;
	for(i=1;i<=200001;i++){
		fac[i]=fac[i-1]*i;
		fac[i]%=mod;
		exgcd(fac[i],mod);
		nfac[i]=((x%mod)+mod)%mod;
	}
	cin>>n>>m>>q;
	for(i=1;i<=n;i++)scanf("%lld",&R[i]),r[i]=R[i];
	for(i=1;i<=m;i++)scanf("%lld",&C[i]),c[i]=C[i];
	sort(r+1,r+1+n);sort(c+1,c+1+m);
	int rcnt=unique(r+1,r+1+n)-(r+1);
	int ccnt=unique(c+1,c+1+m)-(c+1);
	for(i=1;i<=n;i++){
		d1=lower_bound(r+1,r+1+rcnt,R[i])-r;
		numr[d1]++;
	}
	for(i=1;i<=m;i++){
		d2=lower_bound(c+1,c+1+ccnt,C[i])-c;
		numc[d2]++;
	}
	build(1,1,rcnt,0);build(1,1,ccnt,1);
	int x1,x2,y1,y2,dr,dc,dd;
	while(q--){
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		d1=lower_bound(r+1,r+1+rcnt,R[x1])-r;
		d2=lower_bound(r+1,r+1+rcnt,R[x2])-r;
		d3=lower_bound(c+1,c+1+ccnt,C[y1])-c;
		d4=lower_bound(c+1,c+1+ccnt,C[y2])-c;
		dr=d2-d1;dc=d4-d3;
		if(dr<0||dc<0)ANS=0;
		else if((dr==0&&x1!=x2)||(dc==0&&y1!=y2))ANS=0;
		else{
			dd=dr+dc;
			ANS=fac[dd];ANS*=nfac[dr];ANS%=mod;ANS*=nfac[dc];ANS%=mod;
			ANS*=sum(1,1,rcnt,d1+1,d2-1,0);ANS%=mod;
			ANS*=sum(1,1,ccnt,d3+1,d4-1,1);ANS%=mod;
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
