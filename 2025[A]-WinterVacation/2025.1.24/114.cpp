#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int x,y,ff;
}input[10009];
int n,m,k,i,j,r,x,y,ff,a[109][109],F[109];
int find(int x){
	if(F[x]==x)return x;
	else{
		F[x]=find(F[x]);
		return F[x];
	}
}
signed main(){
	freopen("114.in","r",stdin);freopen("114.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&ff);
		input[i].x=x;input[i].y=y;input[i].ff=ff;
		a[x][y]=ff;a[y][x]=ff;
	}
	for(i=1;i<=n;i++)F[i]=i;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(a[i][j]==1){
				if(find(i)!=find(j)){
					F[find(i)]=find(j);
				}
			}
		}
	}
	while(k--){
		scanf("%lld%lld",&x,&y);
		if(a[x][y]!=-1&&find(x)==find(y)){
			printf("No problem\n");
		}
		else if(a[x][y]==0){
			printf("OK\n");
		}
		else{
			if(a[x][y]==-1&&find(x)==find(y)){
				printf("OK but...\n");
			}
			else{
				printf("No way\n");
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
