#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int x,y;
};
nod edg[1009];
int T,n,vis[1009],a[1009][1009],i,j,cnt;
void dfs(int x,int y){
	if(a[x][y]!=-1)return;
	int k;
	printf("? %lld %lld\n",x,y);
	fflush(stdout);
	scanf("%lld",&k);
	if(k==x||k==y){
		a[x][y]=1;a[y][x]=1;
		return;
	}
	else{
		dfs(x,k);dfs(k,y);
	}
}
signed main(){
	//freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)a[i][j]=-1;
		for(i=1;i<=n;i++)vis[i]=0;
		for(i=2;i<=n;i++){
			dfs(1,i);
		}
		cnt=0;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++){
			if(vis[i]==0||vis[j]==0){
				if(a[i][j]!=-1){
					vis[i]=1;vis[j]=1;cnt++;
					edg[cnt].x=i;edg[cnt].y=j;
					fflush(stdout);
				}
			}
		}
		printf("!\n");fflush(stdout);
		for(i=1;i<=cnt;i++){
			printf("%lld %lld\n",edg[i].x,edg[i].y);
			fflush(stdout);
		}
		fflush(stdout);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
