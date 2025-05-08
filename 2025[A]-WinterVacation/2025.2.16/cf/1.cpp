#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,ans;
char c[1009];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);getchar();ans=0;
		for(i=1;i<=n;i++)c[i]=getchar();
		if(c[1]=='1')ans++;
		for(i=2;i<=n;i++){
			if(c[i]!=c[i-1])ans++;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
}
