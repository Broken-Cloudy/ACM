#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[5009],ff;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ff=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(a[1]>0&&a[2]>0){
			for(i=3;i<=n;i++){
				if(a[i]==0){
					ff=1;
					break;
				}
			}
			if(ff==1){
				printf("%lld\n",2LL);
				printf("%lld %lld\n",3LL,n);
				printf("%lld %lld\n",1LL,3LL);
			}
			else{
				printf("%lld\n",1LL);
				printf("%lld %lld\n",1LL,n);
			}
		}
		else if(a[n]>0&&a[n-1]>0){
			for(i=1;i<=n-2;i++){
				if(a[i]==0){
					ff=1;
					break;
				}
			}
			if(ff==1){
				printf("%lld\n",2LL);
				printf("%lld %lld\n",1LL,n-2);
				printf("%lld %lld\n",1LL,3LL);
			}
			else{
				printf("%lld\n",1LL);
				printf("%lld %lld\n",1LL,n);
			}
		}
		else{
			if(n==4){
				printf("%lld\n",3LL);
				printf("%lld %lld\n",n-1,n);
				printf("%lld %lld\n",1LL,2LL);
				printf("%lld %lld\n",1LL,2LL);
				continue;
			}
			for(i=3;i<=n-2;i++){
				if(a[i]==0){
					ff=1;
					break;
				}
			}
			if(ff==1){
				printf("%lld\n",4LL);
				printf("%lld %lld\n",n-1,n);
				printf("%lld %lld\n",1LL,2LL);
				printf("%lld %lld\n",1LL,n-3);
				printf("%lld %lld\n",1LL,2LL);
			}
			else{
				printf("%lld\n",3LL);
				printf("%lld %lld\n",n-1,n);
				printf("%lld %lld\n",1LL,2LL);
				printf("%lld %lld\n",1LL,n-2);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
