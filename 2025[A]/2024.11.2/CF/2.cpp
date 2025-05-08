#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,k,j,r[200009],ans,b,c;
bool ff,f;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);ans=0;
		for(i=1;i<=k;i++)r[i]=0;
		for(i=1;i<=k;i++){
			scanf("%lld%lld",&b,&c);
			r[b]+=c;
		}
		sort(r+1,r+1+k);
		for(i=k;i>=max(1LL,k-n+1);i--){
			ans+=r[i];
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
