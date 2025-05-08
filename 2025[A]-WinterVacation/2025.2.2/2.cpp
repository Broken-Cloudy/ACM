#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,a[200009],k,l,r,kk,ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);ans=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n==k){
			for(i=2;i<=n;i+=2){
				kk=i/2;
				if(a[i]!=kk){
					ans=kk;
					break;
				}
			}
			if(ans==0)ans=k/2+1;
			printf("%lld\n",ans);
		}	
		else{
			for(i=2;i<=n-k+2;i++){
				if(a[i]!=1)ans=1;
			}
			if(ans==0)ans=2;
			printf("%lld\n",ans);	
		}	
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
