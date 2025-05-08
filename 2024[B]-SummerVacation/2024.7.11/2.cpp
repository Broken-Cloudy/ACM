#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[100009],i,cnt,b[100009],ans,mini;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		cnt=0;ans=0;mini=a[1];
		for(i=2;i<=n;i++){
			if(a[i]<mini){
				b[++cnt]=mini-a[i];
			}
			else{
				mini=a[i];
			}
		}
		sort(b+1,b+1+cnt);
		k=0;//基准 
		for(i=1;i<=cnt;i++){
			if(b[i]==k){
				//无操作 
			}
			else{
				ans+=(cnt-(i-1)+1)*(b[i]-k);
				k=b[i];
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
