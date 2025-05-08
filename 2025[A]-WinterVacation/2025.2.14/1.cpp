#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,a[1009],len,j,f[1009][1009],sum,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	if(n==1){
		ans=0;
	}
	else if(n==2){
		ans=min(a[1],a[2]);
	}
	else{
		if(n%2==1){
			for(len=3;len<=n;len+=2){
				for(i=1;i<=n-len+1;i++){
					j=i+len-1;
					if(a[i]>=a[j]){
						f[i][j]=max(f[i][j],f[i+1][j-1]+a[j]);
						f[i][j]=max(f[i][j],f[i+2][j]+a[i+1]);
					}
					else{
						f[i][j]=max(f[i][j],f[i+1][j-1]+a[i]);
						f[i][j]=max(f[i][j],f[i][j-2]+a[j-1]);
					}
					ans=max(ans,f[i][j]);
				}
			}
		}
		else{
			for(i=1;i<n;i++)f[i][i+1]=min(a[i],a[i+1]);
			for(len=4;len<=n;len+=2){
				for(i=1;i<=n-len+1;i++){
					j=i+len-1;
					if(a[i]>=a[j]){
						f[i][j]=max(f[i][j],f[i+1][j-1]+a[j]);
						f[i][j]=max(f[i][j],f[i+2][j]+a[i+1]);
					}
					else{
						f[i][j]=max(f[i][j],f[i+1][j-1]+a[i]);
						f[i][j]=max(f[i][j],f[i][j-2]+a[j-1]);
					}
					ans=max(ans,f[i][j]);
				}
			}
		}
	}
	printf("%lld %lld\n",sum-ans,ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
