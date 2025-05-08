#include<bits/stdc++.h>
#define int long long
using namespace std;
int C[5009][5009],i,n,m,q,j;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	C[0][0]=C[1][0]=C[1][1];
	for(i=2;i<=5000;i++){
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%q;
		}
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
