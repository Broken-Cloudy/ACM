#include<bits/stdc++.h>
#define ll long long
#define int long long
#define ii int
using namespace std;
int n,i,a[500009],l,r,q,b[500009],sum1[500009],sum2[500009],ANS,u,v;
struct nod{
	int szuo,syou,smax;
};
struct NOD{
	int szuo,syou,smax;
	int sszuo,ssyou,ssmax;
};
nod tree1[2000009],tree2[2000009];
NOD tree;
struct nodd{
	int szuo,syou,smax;
	int sszuo,ssyou,ssmax;
};
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
inline void build(ii node,ii start,ii end){//要致富,先建树 
	if(start==end){
		tree1[node].syou=max(0LL,a[start]);
		tree1[node].szuo=max(0LL,a[start]);
		tree1[node].smax=max(0LL,a[start]);
		tree2[node].syou=max(0LL,b[start]);
		tree2[node].szuo=max(0LL,b[start]);
		tree2[node].smax=max(0LL,b[start]);
	}
	else{//node是当前数在树中的坐标 
		ii mid=(start+end)/2;
		ii zuo=2*node;//直接访问左子树 
		ii you=2*node+1;//直接访问右子树 
		build(zuo,start,mid);
		build(you,mid+1,end);
		tree1[node].szuo=max(tree1[zuo].szuo,tree1[you].szuo+suma(1,n,start,mid));
		tree1[node].syou=max(tree1[you].syou,tree1[zuo].syou+suma(1,n,mid+1,end));
		tree1[node].smax=max(tree1[you].smax,tree1[zuo].smax);
		tree1[node].smax=max(tree1[node].smax,max(tree1[zuo].smax,tree1[you].smax));
		tree1[node].smax=max(tree1[node].smax,tree1[zuo].syou+tree1[you].szuo);
		tree2[node].szuo=max(tree2[zuo].szuo,tree2[you].szuo+sumb(1,n,start,mid));
		tree2[node].syou=max(tree2[you].syou,tree2[zuo].syou+sumb(1,n,mid+1,end));
		tree2[node].smax=max(tree2[you].smax,tree2[zuo].smax);
		tree2[node].smax=max(tree2[node].smax,max(tree2[zuo].smax,tree2[you].smax));
		tree2[node].smax=max(tree2[node].smax,tree2[zuo].syou+tree2[you].szuo);
	}
}
inline NOD ans(ii node,ii start,ii end,ii L,ii R){
	NOD z;
	z.smax=0;z.syou=0;z.szuo=0;
	z.ssmax=0;z.ssyou=0;z.sszuo=0;
	if(end<L||start>R)return z;//加速操作!!!
	else if(start>=L&&end<=R){
		z.smax=tree1[node].smax;z.szuo=tree1[node].szuo;z.syou=tree1[node].syou;
		z.ssmax=tree2[node].smax;z.sszuo=tree2[node].szuo;z.ssyou=tree2[node].syou;
		return z;
	}
	else{
		ii mid=(start+end)/2;
		ii zuo=2*node;
		ii you=2*node+1;
		NOD x=ans(zuo,start,mid,L,R);
		NOD y=ans(you,mid+1,end,L,R);
		z.szuo=max(x.szuo,y.szuo+suma(start,mid,L,R));
		z.syou=max(y.syou,x.syou+suma(mid+1,end,L,R));
		z.smax=max(y.smax,x.smax);
		z.smax=max(z.smax,max(x.smax,y.smax));
		z.smax=max(z.smax,x.syou+y.szuo);
		z.sszuo=max(x.sszuo,y.sszuo+sumb(start,mid,L,R));
		z.ssyou=max(y.ssyou,x.ssyou+sumb(mid+1,end,L,R));
		z.ssmax=max(y.ssmax,x.ssmax);
		z.ssmax=max(z.ssmax,max(x.ssmax,y.ssmax));
		z.ssmax=max(z.ssmax,x.ssyou+y.sszuo);
		return z;
	}
}
signed main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;getchar();
	for(i=1;i<=n;i++){
		read(a[i]);
		sum1[i]=sum1[i-1]+a[i];
		b[i]=-a[i];
		sum2[i]=sum2[i-1]+b[i];
	}
	build(1,1,n);
	cin>>q;getchar();
	for(i=1;i<=q;i++){
		read(u);read(v);
		ANS=0;
		tree=ans(1,1,n,u,v);
		ANS=max(tree.smax,tree.ssmax);
		putout(ANS);putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
