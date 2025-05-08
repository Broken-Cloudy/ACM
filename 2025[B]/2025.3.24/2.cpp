#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,i,j,a[3009],ton[3009],l,r;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=0;i<k;i++)ton[a[i]]++;
		for(i=1;i<=n-k+1;i++){//3000
			j=i+k-1;//i--j
			ton[a[i-1]]--;ton[a[j]]++;
			
		}
		for(i=1;i<=n;i++)ton[i]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
