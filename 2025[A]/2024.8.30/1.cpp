#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1009][1009],i,j;
map<map<int,int> ,int>m;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
