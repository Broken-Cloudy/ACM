#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,a[49];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(n>=3){
			printf("NO\n");
		}
		else{
			if(a[2]-a[1]>=2)printf("YES\n");
			else printf("NO\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
