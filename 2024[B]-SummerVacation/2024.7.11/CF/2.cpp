#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,T,ans,i,b,a[200009];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&n,&k);
		ans=0;
		for(i=1;i<=k;i++){
			scanf("%lld",&a[i]);
		}
		b=0;
		for(i=1;i<=k;i++){
			b=max(a[i],b);
		}
		for(i=1;i<=k;i++){
			if(a[i]==1){
				ans++;
			}
			else{
				ans+=(a[i]+(a[i]-1));
			}
		}
		ans-=b+(b-1);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
