#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
int i,n,j,k,dis[109][109],f[109][109],a[109][109];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)dis[i][j]=INF;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i][j]==1)dis[i][j]=1;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(dis[i][j]!=INF){
				f[i][j]=1;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(j<n)printf("%d ",f[i][j]);
			else printf("%d\n",f[i][j]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
