#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef long long ll;
const ll mod=1000000007;
int G=5,invG;
const int N=2400000;
ll ksm(ll b,int n){
    ll res=1;
    while(n){
        if(n&1) res=res*b%mod;
        b=b*b%mod; n>>=1;
    }
    return res;
}
int tr[N];
void NTT(ll *f,int n,int fl){
    for(int i=0;i<n;++i)
        if(i<tr[i]) swap(f[i],f[tr[i]]);
    for(int p=2;p<=n;p<<=1){
        int len=(p>>1);
        ll w=ksm((fl==0)?G:invG,(mod-1)/p);
        for(int st=0;st<n;st+=p){
            ll buf=1,tmp;
            for(int i=st;i<st+len;++i)
                tmp=buf*f[i+len]%mod,
                f[i+len]=(f[i]-tmp+mod)%mod,
                f[i]=(f[i]+tmp)%mod,
                buf=buf*w%mod;
        }
    }
    if(fl==1){
        ll invN=ksm(n,mod-2);
        for(int i=0;i<n;++i)
            f[i]=(f[i]*invN)%mod;
    }
}
ll f[N],g[N],a[N],b[N],fac[N],inv[N];
void init(int n){
    fac[0]=1;
    for(int i=1;i<=n;++i)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=ksm(fac[n],mod-2);
    for(int i=n-1;i>=0;--i)
        inv[i]=1ll*(i+1)*inv[i+1]%mod;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    invG=ksm(G,mod-2);
    int n,m;
    scanf("%lld%lld",&n,&m);
    init(n);
    for(int i=0;i<=n;++i)
        a[i]=(i&1?mod-inv[i]:inv[i]),
        b[i]=ksm(i,n)*inv[i]%mod;
    int limit=1;
    while(limit<=(n<<1)) limit<<=1;
    for(int i=0;i<=limit;++i)
        tr[i]=(tr[i>>1]>>1)|(i&1?limit>>1:0);
    NTT(a,limit,0);NTT(b,limit,0);
    for(int i=0;i<=limit;++i)
        a[i]=a[i]*b[i]%mod;
    NTT(a,limit,1);
    cout<<a[m]<<endl;
    fclose(stdin);fclose(stdout);
    return 0;
}
