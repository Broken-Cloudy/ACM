#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a,b,c;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&a);
		b=1;c=a^b;
		if(c==0||c>1000000000){
			b=2;c=a^b;
		}
		printf("%lld %lld\n",b,c);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
