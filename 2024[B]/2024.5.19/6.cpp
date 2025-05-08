#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
int n,a,b,i,j,w[2000009],ty[2000009];
int f[2000009][5],maxans;//1是击杀了1，2是击杀了2，3是击杀了1，2，0是没有击杀 
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n>>a>>b;
	for(i=1;i<=n;i++){
		scanf("%lld",&w[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&ty[i]);
	}
	for(i=1;i<=n;i++)for(j=0;j<=3;j++)f[i][j]=-inf;
	for(i=1;i<=n;i++){
		f[i][0]=max(f[i][0],f[i-1][0]);
		f[i][1]=max(f[i][1],f[i-1][])
		if(ty[i]==1){
			f[i][1]=f[i-1][0]+w[i];
			if(f[i-1][2]!=-inf)f[i][1]=max(f[i][1],f[i-a][3]+w[i]);
			if(f[i-1][2]!=-inf)f[i][1]=max(f[i][1],f[i-a][1]+w[i]);
			if(f[i-1][2]!=-inf)f[i][3]=max(f[i][3],f[i-1][2]+w[i]);
		}
		else{
			f[i][2]=max(f[i][2],f[i-b][3]+w[i]);
			f[i][3]=max(f[i][3],f[i-1][1]+w[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
