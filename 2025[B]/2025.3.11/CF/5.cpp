#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[7],i,x;
int f[18];
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	f[0]=2;f[1]=3;f[2]=1;f[3]=1;f[4]=3;f[5]=2;f[6]=1;f[7]=3;
	while(T--){
		scanf("%lld",&n);
		a[1]=1;a[2]=2;a[3]=3;
		for(i=1;i<=75;i++){
			printf("? %lld %lld %lld\n",a[1],a[2],a[3]);fflush(stdout);
			scanf("%lld",&x);
			if(x==0){
				break;
			}
			else{
				a[f[i%8]]=x;
			}
		}
		printf("! %lld %lld %lld\n",a[1],a[2],a[3]);fflush(stdout);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
