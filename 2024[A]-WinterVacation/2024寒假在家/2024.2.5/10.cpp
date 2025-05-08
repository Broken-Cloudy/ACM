#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,a[200009],i,mini,ans,sum,cnt,k;
int main(){
	freopen("10.in","r",stdin);freopen("10.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		sum=0;ans=0;
		scanf("%lld",&n);
		if(n==1){
			for(i=1;i<=n;i++){
				scanf("%lld",&k);
			}
			printf("0\n");
			continue;
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&k);
			a[i]=2*k;
		}
		sort(a+1,a+1+n);cnt=n-1;
		mini=a[1]*2;
		ans+=a[1]*cnt+sum;
		sum+=a[1];
		cnt--;
		for(i=2;i<=n;i++){
			if(a[i]<=mini){
				ans+=a[i]*cnt+sum;
				cnt--;
				sum+=a[i];
			}
			else{
				ans+=mini*cnt+sum;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
