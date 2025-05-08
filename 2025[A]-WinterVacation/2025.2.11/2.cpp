#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,b[100009],ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=n;i++)scanf("%lld",&b[i]);
		for(i=2;i<=n;i++){
			if(b[i]!=b[i-1])ans++;
		}
		printf("%lld\n",ans+1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
