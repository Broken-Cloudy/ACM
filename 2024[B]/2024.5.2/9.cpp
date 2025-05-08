#include<bits/stdc++.h>
using namespace std;
const __int128 inf=1e9+7;
__int128 i,f[1000009][4],n,m;
long long N,M,ans;
signed main(){
	//freopen("9.in","r",stdin);freopen("9.out","w",stdout);
	cin>>N>>M;n=N;m=M;
	f[3][0]=m*(m-1)%inf*(m-2)%inf;f[3][1]=m*(m-1)%inf;f[3][2]=m*(m-1)%inf;
	for(i=4;i<=n;i++){
		f[i][0]=f[i-1][0]*(m-2)+f[i-1][1]*(m-2);
		f[i][0]%=inf;
		f[i][1]=f[i-1][2]*(m-2);
		f[i][1]%=inf;
		f[i][2]=f[i-1][0]+f[i-1][1];
		f[i][2]%=inf;
	}
	ans=(f[n][0]%inf+f[n][1]%inf+f[n][2]%inf)%inf;
	if(N==2)ans=m*m;
	else if(N==1)ans=m;
	else if(M==1&&N>=3)ans=0;
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
