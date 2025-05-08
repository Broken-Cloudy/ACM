#include<stdio.h>
#include<string.h>
typedef long long ll;
typedef unsigned int word;
struct READ{
	char c,w;
	inline READ(){
		//freopen("sample.in","r",stdin);
		//freopen("sample.out","w",stdout);
		c=getchar();}
	template<typename type>
	inline READ& operator>>(type &num){
		for(w=1;'0'>c||c>'9';c=getchar())
			w=c=='-'? -1:1;
		for(num=0;'0'<=c&&c<='9';c=getchar())
			num=num*10+(c-'0');
		return num*=w,*this;
	}
}cin;
const ll inf=0x7fff'ffff'ffff'ffff;//+∞
inline ll min(const ll a,const ll b){
	return a<b? a:b;}
/* 向量/矩阵
⎡a⎤   ⎡a +∞⎤
⎣b⎦   ⎣b  0⎦
*/
struct matrix{
	ll a,b;
	inline matrix(){}
	inline matrix(const matrix &p)=default;
	inline matrix(ll A,ll B):a(A),b(B){}
	inline matrix operator+(const matrix &p)const{//矩阵/向量 加法
		return matrix(min(a,p.a),min(b,p.b));}
	inline matrix operator()(const matrix &p)const{//矩阵乘法
		return matrix(a==inf||p.a==inf? inf:a+p.a,
			b==inf||p.a==inf? p.b:min(b+p.a,p.b));
	}
	inline bool operator!=(const matrix &p)const{
		return a!=p.a||b!=p.b;
	}
}const I(0,inf),vec0(inf,inf);
word n,m;
struct segment_tree{//线段树（zkw）
	matrix sum[1<<20],tag[1<<20];
	inline void init(){
		cin>>n>>m;
		for(word i=1;i<=n;++i)
			cin>>sum[1u<<19|i].a,sum[1u<<19|i].b=sum[1u<<19|i].a;
		for(word i=(1u<<19)-1;i;--i)
			sum[i]=sum[i<<1]+sum[i<<1|1];
		for(auto &p:tag) p=I;
	}
	#define l (rt<<1)
	#define r (rt<<1|1)
	inline void pushdown(const word rt){
		if(tag[rt]!=I){
			sum[l]=tag[rt](sum[l]),tag[l]=tag[rt](tag[l]);
			sum[r]=tag[rt](sum[r]),tag[r]=tag[rt](tag[r]);
			tag[rt]=I;
		}
	}
	inline void operator()(const word f,const word t,const matrix &p,
		const word rt=1,const word size=1<<18){
		if(size==0||(f==0&&(t==(size<<1)-1)))
			return sum[rt]=p(sum[rt]),void(tag[rt]=p(tag[rt]));
		pushdown(rt);
		const auto lf=[&](word f,word t){(*this)(f,t,p,l,size>>1);};
		const auto rf=[&](word f,word t){(*this)(f,t,p,r,size>>1);};
		if(f&size) rf(f&~size,t&~size);
		else if((t&size)^size) lf(f,t);
		else lf(f,size-1),rf(0,t&~size);
		sum[rt]=sum[l]+sum[r];
	}
	inline ll geta(const word f,const word t,
		const word rt=1,const word size=1<<18){
			if(size==0||(f==0&&t==(size<<1)-1)) return sum[rt].a;
			pushdown(rt);
			const auto lf=[&](word f,word t)->ll {return geta(f,t,l,size>>1);};
			const auto rf=[&](word f,word t)->ll {return geta(f,t,r,size>>1);};
			if(f&size) return rf(f&~size,t&~size);
			else if((t&size)^size) return lf(f,t);
			return min(lf(f,size-1),rf(0,t&~size));
	}

	inline ll getb(const word f,const word t,
		const word rt=1,const word size=1<<18){
			if(size==0||(f==0&&t==(size<<1)-1)) return sum[rt].b;
			pushdown(rt);
			const auto lf=[&](word f,word t)->ll {return getb(f,t,l,size>>1);};
			const auto rf=[&](word f,word t)->ll {return getb(f,t,r,size>>1);};
			if(f&size) return rf(f&~size,t&~size);
			else if((t&size)^size) return lf(f,t);
			return min(lf(f,size-1),rf(0,t&~size));
	}
	#undef l
	#undef r
}tree;
int main(){
	tree.init();
	for(int opt,l,r;m;--m)
		if(cin>>opt>>l>>r,opt==2)
			printf("%lld\n",tree.geta(l,r));
		else if(opt==3) printf("%lld\n",tree.getb(l,r));
		else cin>>opt,tree(l,r,matrix(opt,opt));
    return 0;
}