#include<bits/stdc++.h>
#define int long long
#define inf 1000000009LL
using namespace std;
int T,i,j,k,n,a[109],f[109][109][109];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=0;i<=n+1;i++)for(j=0;j<=n+1;j++)for(k=0;k<=n+1;k++)f[i][j][k]=inf;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		f[1][1][0]=0,f[1][2][1]=f[1][a[1]+1][a[1]]=1;
		for(k=2;k<=n;k++){//物品 
			for(i=0;i<=n+1;i++){//区间 
				for(j=0;j<=n+1;j++){
					f[k][i][j]=min(f[k][i][j],f[k-1][i][j]);//不选 
					int L=max(1LL,k-a[k]+1);
					int R=min(n,k+a[k]-1);
					if(i<L){
						f[k][i][max(j,k)]=min(f[k-1][i][j]+1,f[k][i][max(j,k)]);
					}
					else{
						f[k][max(i,max(k+1,j+1))][max(j,k)]=min(f[k-1][i][j]+1,f[k][max(i,max(k+1,j+1))][max(j,k)]);
					}
					if(i<k){
						f[k][i][max(j,R)]=min(f[k][i][max(j,R)],f[k-1][i][j]+1);
					}
					else{
						f[k][max(i,R+1)][max(j,R)]=min(f[k][max(i,R+1)][max(j,R)],f[k-1][i][j]+1);
					}
				}
			} 
		}
		printf("%lld\n",f[n][n+1][n]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
