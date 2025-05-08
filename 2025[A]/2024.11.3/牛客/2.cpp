#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,t,poww[15],x,y,i;
int stlen(int x){
    int ans=0;
    while(x){
        x/=10;
        ans++;
    }
    return ans;
}
signed main(){
	//freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;poww[0]=1;
    for(i=1;i<=12;i++){
        poww[i]=poww[i-1]*10;
    }
	while(T--){
		scanf("%lld",&n);
        ans=n;
        t=stlen(n);
        for(i=1;i<=t;i++){
            x=n%10;
            y=n/poww[t-1];
            n-=y*poww[t-1];n*=10;
            n+=y;
            ans=min(ans,n);
        }
        printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
