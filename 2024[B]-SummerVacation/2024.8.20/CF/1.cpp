#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[109],i,j,k,cnt,ans;
bool f;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n);ans=100000009ll;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(k=1;k<=100;k++){//±£ÁôÔªËØ 
			f=0;cnt=0;
			for(i=n;i>=1;i--){
				if(a[i]==k&&f==0){
					f=1;
				}
				if(f==1&&a[i]<k){
					cnt++;
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
