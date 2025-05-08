#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
ll ni[100009],x,y;
const ll mod=1000000007;
int i,cnt,fir[100009],n,ans,vis[100009];
struct nod{
	int u,v,next;
};
nod a[200009];
void exgcd(ll a,ll b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	ll t=x;
	x=y;y=t-(a/b)*y;
}
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs(int u,int ji){
	int i,k=0;
	vis[u]=1;ans=(ans+ji)%mod;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(!vis[v]){
			k++;
		}
	}
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(!vis[v]){
			dfs(v,ji*ni[k]%mod);
		}
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;
	for(i=1;i<=100001;i++){
		exgcd(i,mod);
		ni[i]=((x%mod)+mod)%mod;
	}
	for(i=1;i<=n-1;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1,1);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
