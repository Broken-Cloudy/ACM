#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,x,t,ans;
int Pow[65];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;Pow[0]=1;
	for(i=1;i<=62;i++)Pow[i]=Pow[i-1]*2;
	while(T--){
		scanf("%lld",&x);t=0;
		while((Pow[t+1]-t)<=x){
			t++;
		}
		ans=2*(x+t);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
