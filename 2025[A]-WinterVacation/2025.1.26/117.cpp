#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[10009];
int fir[509],cnt,x,y,i,p,Q,nowans,ans,vis[509],reset[509],ss;
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
int N,M;
void dfs(int u){
	int i;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			dfs(v);
		}
	}
}
signed main(){
	freopen("117.in","r",stdin);freopen("117.out","w",stdout);
	cin>>N>>M;
	for(i=1;i<=M;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	cin>>Q;
	while(Q--){
		scanf("%lld",&p);ss++;nowans=0;
		for(i=0;i<N;i++)vis[i]=reset[i];
		for(i=0;i<N;i++){
			if(vis[i]==0){
				dfs(i);
				nowans++;
			}
		}
		ans=0;reset[p]=1;
		for(i=0;i<N;i++)vis[i]=reset[i];
		for(i=0;i<N;i++){
			if(vis[i]==0){
				dfs(i);
				ans++;
			}
		}
		if(ans>nowans){
			nowans=ans;
			printf("Red Alert: City %lld is lost!\n",p);
		}
		else{
			printf("City %lld is lost.\n",p);
		}
		if(ss==N){
			printf("Game Over.\n");
			break;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
