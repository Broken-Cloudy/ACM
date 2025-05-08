#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[200009];
bool FF;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);FF=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			if(a[i]==i){
				continue;
			}
			else if(a[i]==i+1){
				if(a[i+1]==a[i]-1)continue;
				else{
					FF=1;
					break;
				}
			}
			else if(a[i]==i-1){
				if(a[i-1]==a[i]+1)continue;
				else{
					FF=1;
					break;
				}
			}
			else{
				FF=1;
				break;
			}
		}
		if(FF==0)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
