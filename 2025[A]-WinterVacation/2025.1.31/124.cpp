#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[200009];
int fir[100009],cnt;
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
int N,i,j,n,k,vis[100009];
double Z,r,ans[100009],b[100009],ANS;
void dfs(int u){
	int i;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			if(b[v]>0){
				ANS+=b[v]*(1.0-r)*ans[u];
			}
			else{
				ans[v]=(1.0-r)*ans[u];
				dfs(v);
			}
		}
	}
}
signed main(){
	freopen("124.in","r",stdin);freopen("124.out","w",stdout);
	cin>>N>>Z>>r;r/=100.0;
	if(N==1){
		scanf("%lld",&n);scanf("%lld",&k);b[0]=k;
		ANS=Z*b[0];
		printf("%.0lf\n",ANS);
		return 0;
	}
	for(i=0;i<N;i++){
		scanf("%lld",&n);
		if(n==0){
			scanf("%lld",&k);
			b[i]=k;
		}
		else{
			for(j=1;j<=n;j++){
				scanf("%lld",&k);
				add(i,k);
			}
		}
	}
	ans[0]=Z;dfs(0);ANS-=0.5;
	if(ANS<0)ANS=0;
	printf("%.0lf\n",ANS);
	fclose(stdin);fclose(stdout);
	return 0;
}
