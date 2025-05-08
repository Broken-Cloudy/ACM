#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,a[200009],sum[200009],ans;
bool f,ff;
char c[200009];
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);getchar();
		for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		for(i=1;i<=n;i++)c[i]=getchar();
		i=1;j=n;f=0;ff=0;
		while(i<j){
			if(c[i]=='L')f=1;
			else i++;
			if(c[j]=='R')ff=1;
			else j--;
			if(f==1&&ff==1){
				f=0;ff=0;
				ans+=(sum[j]-sum[i-1]);
				i++;j--;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
