#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,m,i,f[1850009],d;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;f[1]=0;f[2]=1;
	for(i=3;i<=1850000;i++){
		f[i]=f[i-1]+(i-1)*i/2;
	}
	while(T--){
		scanf("%lld",&m);
        d=upper_bound(f+1,f+1+1850000,m)-f-1;
        printf("%lld\n",d);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
