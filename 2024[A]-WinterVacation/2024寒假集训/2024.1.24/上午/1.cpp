#include<bits/stdc++.h>
using namespace std;
int n,m,k,i,j,C;
int f[109][109][109],a[109][109];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	while(~scanf("%d%d%d",&n,&m,&C)){
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)f[i][j][0]=1;
		if(a[1][1]<=C)f[1][1][a[1][1]]=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				for(k=0;k<=C;k++){
					if(i-1>=1&&f[i-1][j][k]==1){
						if(k+a[i][j]<=C){
							f[i][j][k+a[i][j]]=1;
						}
						f[i][j][k]=1;
					}
					if(j-1>=1&&f[i][j-1][k]==1){
						if(k+a[i][j]<=C){
							f[i][j][k+a[i][j]]=1;
						}
						f[i][j][k]=1;
					}
				}
			}
		}
		for(i=C;i>=0;i--){
			if(f[n][m][i]==1)break;
		}
		printf("%d\n",i);
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)for(k=1;k<=C;k++)f[i][j][k]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
