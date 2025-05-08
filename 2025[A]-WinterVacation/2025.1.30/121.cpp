#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,a[100009],i,sum,ans;
signed main(){
	freopen("121.in","r",stdin);freopen("121.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++)scanf("%lld",&a[i]),sum+=a[i];
	sort(a+1,a+1+N);
	if(N%2==0){
		for(i=1;i<=N/2;i++)ans+=a[i];
		printf("Outgoing #: %lld\n",N/2);
		printf("Introverted #: %lld\n",N/2);
		printf("Diff = %lld\n",abs(sum-ans*2));
	}
	else{
		for(i=1;i<=N/2;i++)ans+=a[i];
		if(abs(sum-ans*2)<abs(sum-(ans+a[N/2+1])*2)){
			printf("Outgoing #: %lld\n",N/2);
			printf("Introverted #: %lld\n",N/2+1);
			printf("Diff = %lld\n",abs(sum-(ans+a[N/2+1])*2));
		}
		else{
			printf("Outgoing #: %lld\n",N/2+1);
			printf("Introverted #: %lld\n",N/2);
			printf("Diff = %lld\n",abs(sum-ans*2));
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
