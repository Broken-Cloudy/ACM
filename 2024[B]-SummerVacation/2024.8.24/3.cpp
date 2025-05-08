#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int x,y;
};
nod edg[1009];
int T,n,vis[1009],a[1009][1009],i,j,cnt;
void dfs(int x,int y){
	if(a[x][y]!=-1||a[y][x]!=-1)return;
	if(cnt==n-1)return;
	int k;
	printf("? %lld %lld\n",x,y);fflush(stdout);
	scanf("%lld",&k);
	if(k==x||k==y){
		if(a[x][y]!=-1||a[y][x]!=-1)return;
		cnt++;
		a[x][y]=a[y][x]=1;
		edg[cnt].x=x;edg[cnt].y=y;
	}
	else{
		a[x][y]=a[y][x]=0;
		if(a[x][k]==-1&&a[k][x]==-1)dfs(x,k);
		if(a[k][y]==-1&&a[y][k]==-1)dfs(k,y);
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)a[i][j]=-1;
		for(i=1;i<=n;i++)vis[i]=0;
		for(i=2;i<=n;i++){
			dfs(1,i);
		}
		printf("! ");fflush(stdout);
		for(i=1;i<=cnt;i++){
			printf("%lld %lld ",edg[i].x,edg[i].y);
			fflush(stdout);
		}
		printf("\n");fflush(stdout);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
