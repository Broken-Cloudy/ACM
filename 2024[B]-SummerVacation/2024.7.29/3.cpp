#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int T,n,ANS,m,i,j,f[5009][5009];
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		f[i][i]=1;
		for(j=i+1;j<=n;j++){
			f[i][j]=(f[i][j-1]*i+f[i-1][j-1])%mod;
		}
	}
	ANS=f[m][n]%mod;
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
