#include<bits/stdc++.h>
#define ll long long
const ll inf=1000000007,mod=1000000009;
using namespace std;
struct nod{
	ll l,r;
};
bool cmp(nod x,nod y){
	return x.l<y.l;
}
nod query[200009];
map<ll,ll>m;
ll n,q,i,a[100009],s[100009],l,r,powe[100009],zhen[100009],dao[100009],len[100009];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>q;powe[1]=1;powe[0]=1;
	for(i=2;i<=100000;i++)powe[i]=powe[i-1]*inf%mod;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){//´´½¨¼òµ¥Á´ 
		if(m.count(a[i]))s[m[a[i]]]=i;
		m[a[i]]=i;
	}
	for(i=1;i<=n;i++){
        zhen[i]=(zhen[i-1]*inf%mod+a[i])%mod;
    }
    for(i=n;i>=1;i--){
        dao[i]=(dao[i+1]*inf%mod+a[i])%mod;
    }
	for(i=1;i<=n;i++){
		ll t=s[i];
		l=i;
		while(t>0){
			r=t;
			ll mid=(l+r)/2;
            ll ans1=(zhen[mid]+inf-zhen[l-1]*powe[mid-l+1]%inf)%inf;
            ll ans2=(dao[mid]+inf-dao[r+1]*powe[r-mid+1]%inf)%inf;
            if(ans1==ans2){
            	len[i]=l-r+1;
            	break;
			}
		}
	}
	for(i=1;i<=q;i++){
		scanf("%lld%lld",&query[i].l,&query[i].r);
	}
	sort(query+1,query+1+q,cmp);
	
	fclose(stdin);fclose(stdout);
	return 0;
}
