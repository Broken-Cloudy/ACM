#include<bits/stdc++.h>
#define ll long long
#define int long long
#define ii int
using namespace std;
int n,i,a[500009],l,r,q,b[500009],sum1[500009],sum2[500009],ANS,u,v;
struct nod{
	int szuo,syou,smax;
};
nod tree1[4000009],tree2[4000009],tree;
inline void read(int &r){
	int f=1;r=0;
	char s=getchar();
	while(s>'9'||s<'0'){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(s<='9'&&s>='0'){
		r=r*10+(s-'0');
		s=getchar();
	}
    r=r*f;
}
inline void putout(int x){
	if(x>0){
		putout(x/10);
		putchar(x%10+48);
	}
}
inline ll suma(ii start,ii end,ii L,ii R){
	l=max(start,L);
	r=min(end,R);
	if(r<l)return 0;
	else{
		return sum1[r]-sum1[l-1];
	}
}
inline ll sumb(ii start,ii end,ii L,ii R){
	l=max(start,L);
	r=min(end,R);
	if(r<l)return 0;
	else{
		return sum2[r]-sum2[l-1];
	}
}
inline void build1(ii node,ii start,ii end){//要致富,先建树 
	if(start==end){
		tree1[node].syou=max(0LL,a[start]);
		tree1[node].szuo=max(0LL,a[start]);
		tree1[node].smax=max(0LL,a[start]);//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ii mid=(start+end)/2;
		ii zuo=2*node;//直接访问左子树 
		ii you=2*node+1;//直接访问右子树 
		build1(zuo,start,mid);
		build1(you,mid+1,end);
		tree1[node].szuo=max(tree1[zuo].szuo,tree1[you].szuo+suma(1,n,start,mid));
		tree1[node].syou=max(tree1[you].syou,tree1[zuo].syou+suma(1,n,mid+1,end));
		tree1[node].smax=max(tree1[you].smax,tree1[zuo].smax);
		tree1[node].smax=max(tree1[node].smax,max(tree1[zuo].smax,tree1[you].smax));
		tree1[node].smax=max(tree1[node].smax,tree1[zuo].syou+tree1[you].szuo);
	}
}
inline void build2(ii node,ii start,ii end){//要致富,先建树 
	if(start==end){
		tree2[node].syou=max(0LL,b[start]);
		tree2[node].szuo=max(0LL,b[start]);
		tree2[node].smax=max(0LL,b[start]);//或return a[end] 
	}
	else{//node是当前数在树中的坐标 
		ii mid=(start+end)/2;
		ii zuo=2*node;//直接访问左子树 
		ii you=2*node+1;//直接访问右子树 
		build2(zuo,start,mid);
		build2(you,mid+1,end);
		tree2[node].szuo=max(tree2[zuo].szuo,tree2[you].szuo+sumb(1,n,start,mid));
		tree2[node].syou=max(tree2[you].syou,tree2[zuo].syou+sumb(1,n,mid+1,end));
		tree2[node].smax=max(tree2[you].smax,tree2[zuo].smax);
		tree2[node].smax=max(tree2[node].smax,max(tree2[zuo].smax,tree2[you].smax));
		tree2[node].smax=max(tree2[node].smax,tree2[zuo].syou+tree2[you].szuo);
	}
}
inline nod ans1(ii node,ii start,ii end,ii L,ii R){
	nod z;z.smax=0;z.syou=0;z.szuo=0;
	if(end<L||start>R)return z;//加速操作!!!
	else if(start>=L&&end<=R)return tree1[node];
	else{
		ii mid=(start+end)/2;
		ii zuo=2*node;
		ii you=2*node+1;
		nod x=ans1(zuo,start,mid,L,R);
		nod y=ans1(you,mid+1,end,L,R);
		z.szuo=max(x.szuo,y.szuo+suma(start,mid,L,R));
		z.syou=max(y.syou,x.syou+suma(mid+1,end,L,R));
		z.smax=max(y.smax,x.smax);
		z.smax=max(z.smax,max(x.smax,y.smax));
		z.smax=max(z.smax,x.syou+y.szuo);
		return z;
	}
}
inline nod ans2(ii node,ii start,ii end,ii L,ii R){
	nod z;z.smax=0;z.syou=0;z.szuo=0;
	if(end<L||start>R)return z;//加速操作!!!
	else if(start>=L&&end<=R)return tree2[node];
	else{
		ii mid=(start+end)/2;
		ii zuo=2*node;
		ii you=2*node+1;
		nod x=ans2(zuo,start,mid,L,R);
		nod y=ans2(you,mid+1,end,L,R);
		z.szuo=max(x.szuo,y.szuo+sumb(start,mid,L,R));
		z.syou=max(y.syou,x.syou+sumb(mid+1,end,L,R));
		z.smax=max(y.smax,x.smax);
		z.smax=max(z.smax,max(x.smax,y.smax));
		z.smax=max(z.smax,x.syou+y.szuo);
		return z;
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;getchar();
	for(i=1;i<=n;i++){
		read(a[i]);
		sum1[i]=sum1[i-1]+a[i];
		b[i]=-a[i];
		sum2[i]=sum2[i-1]+b[i];
	}
	build1(1,1,n);
	build2(1,1,n);
	cin>>q;getchar();
	for(i=1;i<=q;i++){
		read(u);read(v);
		ANS=0;
		tree=ans1(1,1,n,u,v);
		ANS=max(ANS,tree.smax);
		tree=ans2(1,1,n,u,v);
		ANS=max(ANS,tree.smax);
		putout(ANS);putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
