#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,y,ans,pow2[62],i,t,anst;
int f1[59],f2[59],cnt;
signed main(){
	freopen("12.in","r",stdin);freopen("12.out","w",stdout);
	cin>>x>>y;
	pow2[0]=1;
	for(i=1;i<=60;i++)pow2[i]=pow2[i-1]*2;
	if(x==y){
		printf("%lld\n",ans);
	}
	else if(x<y){
		while(pow2[t]<=y&&pow2[t+1]>y){
			t++;
		}
		while(x<=pow2[t]){
			
		}
		if(pow2[t]>(y/2)){//可以向上 
			anst=t;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
