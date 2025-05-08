#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[1009][1009],i,j,vis[1009],VIS[1009];
void dfs(int u,int v){
	if(u==v)return;
	int i,x;
	if(!a[u][v]&&(!vis[u]||!vis[v])){
		printf("? %lld %lld\n",u,v);fflush(stdout);
		scanf("%lld",&x);
		if(x==u||x==v){
			a[u][v]=a[v][u]=1;
			VIS[u]=1;VIS[v]=1;
		}
		else{
			a[u][v]=a[v][u]=-1;
			dfs(u,x);dfs(x,v);
		}
	}
}
signed main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				a[i][j]=0;
			}
			vis[i]=VIS[i]=0;
		}
		for(i=1;i<=n;i++){
			dfs(1,i);
			for(j=1;j<=n;j++)vis[j]=VIS[j];
		}
		printf("! ");fflush(stdout);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(a[i][j]==1&&i<j){
					printf("%lld %lld ",i,j);fflush(stdout);
				}
			}
		}
		cout<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
