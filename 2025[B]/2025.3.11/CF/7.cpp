#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[409],i,f[409][409],j,len,k;
signed main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)f[i][j]=0;
		for(len=3;len<=n;len++){
			for(i=1;i<=n-len+1;i++){
				j=i+len-1;
				for(k=1;k<=n;k++){
					if(i!=k&&j!=k){
						f[i][j]=max(f[i][j],a[i]*a[j]*a[k]+f[i][k]+f[k][j]);
					}
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
