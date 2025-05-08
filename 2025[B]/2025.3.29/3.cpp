#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[200009],maxx,sum1,sum2,ans;
bool f1,f2;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);f1=f2=0;maxx=0;
		sum1=0;sum2=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			maxx=max(maxx,a[i]);
		}
		for(i=1;i<=n;i++){
			if(a[i]%2==0){
				f1=1;
				sum1+=a[i];
			}
			if(a[i]%2==1){
				if(f2==1)sum2+=(a[i]-1);
				else sum2+=a[i];
				f2=1;
			}
		}
		if(f1==1&&f2==1){
			ans=sum1+sum2;
			printf("%lld\n",ans);
		}
		else printf("%lld\n",maxx);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
