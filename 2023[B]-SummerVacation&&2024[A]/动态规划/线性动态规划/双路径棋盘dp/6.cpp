#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,tu[10][10],i,j,k,r;
int f[11][11][11][11];
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n;scanf("%d%d%d",&a,&b,&c);
	while(a!=0&&b!=0&&c!=0){
		tu[a][b]=c;
		scanf("%d%d%d",&a,&b,&c);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				for(r=1;r<=n;r++){
					f[i][j][k][r]=max(max(f[i-1][j][k-1][r],f[i][j-1][k][r-1]),max(f[i-1][j][k][r-1],f[i][j-1][k-1][r]))+tu[i][j]+tu[k][r];
					if(i==k&&j==r)f[i][j][k][r]-=tu[i][j];
				}
			}
		}
	}
	cout<<f[n][n][n][n]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
