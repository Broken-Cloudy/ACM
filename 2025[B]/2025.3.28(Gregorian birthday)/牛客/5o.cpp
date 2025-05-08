#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[2009],i,j,GCD,k[2009],f[2009][2009],kk,dp[2009];
bool FF=1;
void gcd(int a,int b){
	if(b==0){
		GCD=a;
		return;
	}
	else gcd(b,a%b);
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	k[++k[0]]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			gcd(a[i],a[j]);
			if(GCD>1)f[i][j]=1;
		}
	}
	for(i=1;i<=n;i++){
		for(j=i-1;j>=1;j--){
			
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
