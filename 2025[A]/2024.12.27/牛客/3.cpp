#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,x,y;
char S[500009];
struct nod{
	int u,v,next;
}a[1000009];
int cnt,fir[500009],vis[500009],R[500009],B[500009],ans[500009];
int sum1[500009],sum2[500009];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs(int u){
	int i;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			dfs(v);
			R[u]+=R[v];
			B[u]+=B[v];
		}
	}
	if(S[u]=='R')R[u]++;
	else B[u]++;
	ans[u]=abs(R[u]-B[u]);
}
void dfss1(int u){
	int i,r,b,anss;
	vis[u]=0;
	r=R[u];b=B[u];
	if(S[u]=='R'){
		r--;b++;	
	}
	else{
		r++;b--;
	}
	anss=abs(r-b);
	anss=ans[u]-anss;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==1){
			sum1[v]=sum1[u]+anss;
			dfss1(v);
		}
	}
	if(S[u]=='R'){
		
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld\n",&n);getchar();
		for(i=1;i<=n;i++)fir[i]=vis[i]=R[i]=B[i]=0;cnt=0;
		for(i=1;i<=n;i++)S[i]=getchar();
		for(i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
		}
		dfs(1);
		dfss1(1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
