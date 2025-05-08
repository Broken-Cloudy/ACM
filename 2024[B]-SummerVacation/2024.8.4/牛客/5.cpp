#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=10009;
int T,n,i,j,a[5009],f[5009][5009];
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)f[1][i]=inf;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=1;i<=n;i++){
			if(i>=2){
				for(j=0;j<=n;j++){
					f[i][j]=f[i-1][j];
				}
			}
			for(j=i-a[i];j<=i-1;j++){
				if(j>=0&&j+a[i]-1<=n){
					if(f[i][j]!=inf){
						f[i][j+a[i]]=min(f[i][j]+1,f[i][j+a[i]]);
					}
				}
			}
		}
		if(f[n][n]==inf){
			printf("-1\n");
		}
		else{
			printf("%lld\n",f[n][n]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
