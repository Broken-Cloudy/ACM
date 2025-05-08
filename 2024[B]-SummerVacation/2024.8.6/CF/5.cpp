#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,l,r,op,t;
int a[200009],sum[200009],i,ans;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	for(i=1;i<=200000;i++){
		op=0;t=i;
		while(t>0){
			op++;
			t/=3;
		}
		a[i]=op;
	}
	for(i=1;i<=200000;i++){
		sum[i]=sum[i-1]+a[i];
	}
	while(T--){
		scanf("%lld%lld",&l,&r);
		ans=sum[r]-sum[l];
		ans+=2*a[l];
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
