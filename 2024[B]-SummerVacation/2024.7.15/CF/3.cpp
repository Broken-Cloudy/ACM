#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[10009],cnt,i;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		cnt=0;
		for(i=60;i>=0;i--){
			if((n&(1LL<<i))>0&&(1LL<<i)<n){
				a[++cnt]=n^(1LL<<i);
			}
		}
		printf("%lld\n",cnt+1);
		for(i=1;i<=cnt;i++){
			printf("%lld ",a[i]);
		}
		printf("%lld\n",n);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
