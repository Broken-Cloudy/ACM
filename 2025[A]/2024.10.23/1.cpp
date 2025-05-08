#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	printf("%lld\n",2*n-1);
	for(i=1;i<=2*n-1;i++){
		printf("%lld %lld\n",i,i);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
