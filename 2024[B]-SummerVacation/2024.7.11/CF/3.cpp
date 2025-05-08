#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,T,ans,i,b,a[200009];
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld%lld",&n,&m,&k);
		for(i=n;i>m;i--){
			printf("%lld ",i);
		}
		for(i=1;i<=m;i++){
			if(i!=m)printf("%lld ",i);
			else printf("%lld\n",i);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
