#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int next,u,v;
}a[10009];
int T;
int fir[5009],n,i,j,val[5009],x,y,cnt,vis[5009],f[5009][5009],ans;
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs(int u){
	int i,v,sum=0;
	deque<int>dq;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		v=a[i].v;
		if(vis[v]==0){
			dfs(v);dq.push_back(v);
		}
	}
	if(dq.empty()==1)f[u][0]=1;//р╤вс 
	else{
		f[u][0]=1000000009;
		while(!dq.empty()){
			v=dq.front();dq.pop_front();
			f[u][0]=min(f[u][0],f[v][0]+1);
			sum+=val[v];
			for(i=1;i<=f[v][0];i++){
				f[u][i+1]+=f[v][i];
			}
		}
		if(val[u]-sum<=0){//OK
			f[u][1]=sum-val[u];
		}
		else{
			int d=val[u]-sum;
			f[u][1]=0;
			for(i=1;i<=f[u][0];i++){
				if(d==0)break;
				if(d>=f[u][i]){
					ans+=f[u][i]*(i-1);
					d-=f[u][i];f[u][i]=0;
				}
				else{
					ans+=d*(i-1);
					f[u][i]-=d;d=0;
				}
				if(d==0)break;
			}
			if(d>0){
				ans+=d*(f[u][0]-1);
				d=0;
			}
		}
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=n;i++)fir[i]=vis[i]=0;cnt=0;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)f[i][j]=0;
		for(i=1;i<=n;i++)scanf("%lld",&val[i]);
		for(i=2;i<=n;i++){
			scanf("%lld",&x);
			add(i,x);add(x,i);
		}
		dfs(1);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
