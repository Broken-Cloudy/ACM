#include<bits/stdc++.h>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,a[200009],i,mini,ans,sum,cnt,k;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("9.in","r",stdin);freopen("9.out","w",stdout);
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
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=n;i++){
			ans=ans+sum+a[i]*(n-i);
			sum+=a[i];
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
