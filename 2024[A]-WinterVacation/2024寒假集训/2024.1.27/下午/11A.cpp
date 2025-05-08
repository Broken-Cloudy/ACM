#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,x,a[10010],sum;
ll lcm(ll a,ll b)
{
    return a/__gcd(a,b)*b;
}
void dfs(int u,ll tlcm,int sz)
{
    if(tlcm>m)  return;
    if(u>n)
    {
        ll num=(m-1)/tlcm;
        if(sz==0)  return;
        if(sz&1)  sum+=num*(num+1)*tlcm/2;
        else  sum-=num*(num+1)*tlcm/2;
        return;
    }
    if(tlcm%a[u]==0)  return;
    dfs(u+1,tlcm,sz);
    dfs(u+1,lcm(tlcm,a[u]),sz+1);
}
int main()
{
	freopen("11A.in","r",stdin);freopen("11A.out","w",stdout);
    char ch='#';
    t=1;
    for(int c=1;c<=t;c++)
    {
        int flag=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            a[i]=__gcd(x,m);
            if(a[i]==1)  flag=1;
        }
        if(flag)  sum=m*(m-1)/2;
        else
        {
            ll cnt=unique(a+1,a+n+1)-a;
            sum=0;
            dfs(1,1,0);
        }
        cout<<sum<<'\n';
    }
    fclose(stdin);fclose(stdout);
	return 0;
}
