#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
#define int long long
const int p=1000000007ll,w=5,N=2e6+10;
inline int qpow(int a,int b){
    int k=1ll;
    while(b){
        if(b&1) k=k*a%p;
        a=a*a%p;
        b=b>>1;
    }
    return k;
}
int inv[N],n,f[N],g[N],lim,len,rev[N],m;
inline int upmod(int x){
    return (x%p+p)%p;
}
inline void ntt(int *a,int f){
    for(int i=0;i<lim;i++){
    	if(i<rev[i])swap(a[i],a[rev[i]]);
	}
    for(int mid=1;mid<lim;mid<<=1){
        int wn=qpow(w,(((p-1)/(mid<<1)*f)+p-1));
        for(int j=0;j<lim;j+=(mid<<1)){
            int g=1;
            for(int k=0;k<mid;k++,g=g*wn%p){
                int x=a[k+j],y=g*a[k+j+mid]%p;
                a[k+j]=upmod(x+y);
                a[k+j+mid]=upmod(x-y+p);
            }
        }
    }
    if(f==-1){
        int Inv=qpow(lim,(p-4));
        for(int i=0;i<lim;i++)a[i]=a[i]*Inv%p;
    }
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    cin>>n>>m;n++;
    inv[0]=1;
    for(int i=1;i<n;i++)inv[i]=inv[i-1]*i%p;
    for(int i=1;i<n;i++)inv[i]=qpow(inv[i],p-4);
    for(int i=0;i<n;i++){
        f[i]=(i&1?(p-inv[i]):inv[i]);
        g[i]=qpow(i,n-1)*inv[i]%p;
    }
    lim=1,len=0;
    while(lim<=(n<<1))len++,lim<<=1;
    for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
    ntt(f,1);ntt(g,1);
    for(int i=0;i<lim;i++)f[i]=f[i]*g[i]%p;
    ntt(f,-1);
    printf("%lld ",f[m]);
	fclose(stdin);fclose(stdout);
	return 0;
}
