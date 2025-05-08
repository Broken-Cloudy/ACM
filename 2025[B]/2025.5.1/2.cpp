#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,s,i,x,y,cnt,a[200009],f[200009],t,ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&x);ans=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		t=x;
		while(true){
			if(f[t]>=10)break;
			f[t]++;
			t=a[t];
		}
		for(i=1;i<=n;i++){
			if(f[i]==1)ans++;
		}
		printf("%lld\n",ans);
		for(i=1;i<=n;i++)f[i]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
