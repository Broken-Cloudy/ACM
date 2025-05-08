#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,L,R,l,r,ans,i,a[109];
bool f,ff;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		scanf("%lld%lld",&L,&R);
		scanf("%lld%lld",&l,&r);
		for(i=1;i<=100;i++)a[i]=0;// 
		for(i=L;i<=R;i++)a[i]++;//µã 
		for(i=l;i<=r;i++)a[i]++;
		for(i=1;i<=100;i++){
			if(a[i]==1&&a[i+1]==2)ans++;
			else if(a[i]==2&&a[i+1]==1)ans++;
			else if(a[i]==2&&a[i+1]==2)ans++;
		}
		ans=max(1LL,ans);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
