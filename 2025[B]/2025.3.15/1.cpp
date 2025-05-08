#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[809],i,f[809][809],j,len,k,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=2*n;i++)for(j=1;j<=2*n;j++)f[i][j]=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			a[i+n]=a[i];
		}
		for(len=3;len<=n;len++){
			for(i=1;i<=2*n-len+1;i++){
				j=i+len-1;
				for(k=i+1;k<j;k++){//ÌôÑ¡Èý½ÇÐÎ 
					f[i][j]=max(f[i][j],a[i]*a[j]*a[k]+f[i+1][k-1]+f[k+1][j-1]);
				}
				for(k=i;k<j;k++){
					f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
				}
			}
		}
		for(i=1;i<=n;i++){
			ans=max(ans,f[i][i+n-1]);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
