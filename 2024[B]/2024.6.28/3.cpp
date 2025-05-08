#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9+7;
int n,x,i,j,k;
int C[1009][1009];
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>x;
	for(i=1;i<=1001;i++){
		if(i*i>x){
			k=i-1;
			break;
		}
	}
	C[1][0]=1;C[1][1]=1;
	C[2][0]=1;C[2][1]=2;C[2][2]=1;
	for(i=1;i<=1000;i++){
		C[i][0]=1;C[i][i]=1;
		for(j=1;j<i;j++){
			C[i][j]=C[i-1][j-1]%inf+C[i-1][j]%inf;
			C[i][j]%=inf;
		}
	}
	printf("%lld\n",C[k][n]);
	fclose(stdin);fclose(stdout);
	return 0;
}
