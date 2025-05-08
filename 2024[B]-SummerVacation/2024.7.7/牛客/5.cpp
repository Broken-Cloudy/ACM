#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=998244353;
int i,n,u,v,vis[1000009],ans,f[1000009],lea[1000009],depth,ANS,K=1;
struct nod{
	int next,v;
};
nod a[4000009];
int cnt,fir[1000009],dp[1000009];
void add(int u,int v){
	cnt++;
	a[cnt].next=fir[u];
	a[cnt].v=v;
	fir[u]=cnt;
}
void DFS(int u,int deep){
	int i,v;
	depth=max(depth,deep);
	int ff=0;
	for(i=fir[u];i;i=a[i].next){
		v=a[i].v;
		if(vis[v]==0){
			vis[v]=1;ff=1;
			DFS(v,deep+1);
		}
	}
	dp[deep]++;
	if(ff==0)lea[deep]++;
}
int x,y;
void exgcd(int a,int b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;y=t-(a/b)*y;
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
    cin>>n;
    for(i=1;i<=1000000;i++){
		exgcd(i,inf);
		f[i]=(x%inf+inf)%inf;
	}
    for(i=1;i<=n-1;i++){
    	scanf("%lld%lld",&u,&v);
    	add(u,v);add(v,u);
	}
	vis[1]=1;
	DFS(1,0);
	for(i=0;i<=depth;i++){
		ANS=f[dp[i]]*lea[i];ANS%=inf;
		ANS*=i;ANS%=inf;
		ANS*=K;ANS%=inf;//»ùÊý 
		K*=f[dp[i]];K%=inf;K*=(dp[i]-lea[i]);K%=inf;
		ans=(ans+ANS)%inf;
	}
	cout<<(ans%inf+inf)%inf<<endl;
	fclose(stdin);fclose(stdout);
    return 0;
}
