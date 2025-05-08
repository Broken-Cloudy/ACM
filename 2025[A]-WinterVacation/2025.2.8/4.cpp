#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,m,n;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		if(n==0||m==0)printf("No\n");
		else{
			printf("Yes\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
