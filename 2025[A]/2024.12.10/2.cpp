#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[200009],sum,sum1,sum2,r1,r2;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);sum=sum1=sum2=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
			if(i%2)sum1+=a[i];
			else sum2+=a[i];
		}
		if(sum%n!=0){
			printf("NO\n");
			continue;
		}
		else{
			int kk=sum/n;
			r1=(n+1)/2;r2=n/2;
			if(kk==sum1/r1&&kk==sum2/r2){
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
