#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,l,r,i,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&l,&r);ans=0;
		while(l<=r){
			if(l%2==0){
				l++;
				continue;
			}
			else{
				if(l+2<=r){
					ans++;
					l+=3;
				}
				else break;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
