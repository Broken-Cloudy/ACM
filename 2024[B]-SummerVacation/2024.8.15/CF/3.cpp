#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,i,a[200009],sum;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+1+n,cmp);sum=0;
		for(i=1;i<=n;i++){
			if(i%2==0){
				int d=a[i-1]-a[i];
				if(k<d){
					a[i]+=k;
					k=0;
				}
				else{
					a[i]+=d;
					k-=d;
				}
				sum-=a[i];
			}
			else sum+=a[i];
		}
		printf("%lld\n",sum);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
