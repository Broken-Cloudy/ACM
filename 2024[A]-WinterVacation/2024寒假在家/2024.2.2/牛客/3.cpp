#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,Q,tc,t[100009],i,M,sum[100009];
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>Q>>tc;
	for(i=1;i<=n;i++){
		scanf("%lld",&t[i]);
	}
	sort(t+1,t+1+n);
	for(i=1;i<=n;i++){
		sum[n-i]=sum[n-i+1]+t[i];
	}
	for(i=1;i<=Q;i++){
		scanf("%lld",&M);
		ll d=M/tc;
		if(d>n)d=n;
		printf("%lld\n",sum[d]+tc);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
