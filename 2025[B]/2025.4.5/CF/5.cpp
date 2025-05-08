#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1000000007LL;
int T,i,a[5009],n,len,j,ANS,f[5009][5009],g[5009][5009];
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(len=1;len<=n;len++){
			for(i=1;i<=n-len+1;i++){
				j=i+len-1;//i--j
				
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
