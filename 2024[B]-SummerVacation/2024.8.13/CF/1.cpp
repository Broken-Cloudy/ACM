#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,b[100009];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(i=102;i<=109;i++)b[i]=1;
	for(i=1010;i<=1099;i++)b[i]=1;
	for(i=10100;i<=10999;i++)b[i]=1;
	while(T--){
		scanf("%lld",&n);
		if(b[n]==1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
