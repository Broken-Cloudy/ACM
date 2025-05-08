#include<bits/stdc++.h>
#define int long long
#define inf 1000000000000000009LL
using namespace std;
int T,i,n,m,q,t,p[100009],b[100009],fir[100009],x,y,z,cnt,ans;
int dp[100009];
struct nod{
	int u,v,w,next;
}a[200009];
int divs;
void add(int x,int y,int z){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;a[cnt].w=z;
	fir[x]=cnt;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m>>q;
	divs=sqrt(m);//定义块的大小 
	for(i=1;i<=n;i++){
		scanf("%lld",&p[i]);
	}
	for(i=1;i<=m;i++){
		
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	for(i=1;i<=q;i++){
		scanf("%lld",&b[i]);
	}
	for(t=q;t>=1;t--){//倒序遍历 
		int u=b[t];dp[u]=inf;
		for(i=fir[u];i;i=a[i].next){
			int v=a[i].v;
			dp[u]=min(dp[u],dp[v]+a[i].w);
		}
	}
	for(i=1;i<=n;i++){
		ans+=p[i]*dp[i];
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
