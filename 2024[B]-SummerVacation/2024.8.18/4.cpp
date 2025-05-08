#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,a[10009],ans;
bool cmp(int x,int y){
	return x>y;
}
bool check(int x,int y,int z){
	if(z+y>x){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=-1;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=n-2;i++){
			if(check(a[i],a[i+1],a[i+2])==1){
				ans=a[i]+a[i+1]+a[i+2];
				break;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
