#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,i,a[100009],maxx,mini,ans,sum;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);sum=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		sort(a+1,a+1+n);
		maxx=a[n];mini=a[1];
		if(maxx-mini>k+1){
			printf("Jerry\n");
		}
		else if(maxx-mini==k+1&&a[n-1]==a[n]){
			printf("Jerry\n");
		}
		else{
			if(sum%2==0)printf("Jerry\n");
			else printf("Tom\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
