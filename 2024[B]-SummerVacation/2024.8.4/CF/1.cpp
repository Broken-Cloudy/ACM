#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,k[6],i;
char c;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);getchar();ans=0;
		k[1]=n;k[2]=n;k[3]=n;k[4]=n;
		for(i=1;i<=4*n;i++){
			c=getchar();
			if(k[c-'A'+1]>0)k[c-'A'+1]--,ans++;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
