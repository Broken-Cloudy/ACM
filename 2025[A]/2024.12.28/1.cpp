#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[209];
bool FF=0;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;FF=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<n;i++){
			if((a[i]+a[i]>a[i+1])&&(a[i+1]+a[i+1]>a[i])){
				FF=1;
				break;
			}
		}
		if(FF==0)printf("NO\n");
		else printf("YES\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
