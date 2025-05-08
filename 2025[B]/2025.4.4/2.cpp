#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,f[65539],a[1009],i,j,ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	f[0]=1;
	for(i=1;i<=n;i++){
		if(a[i]==0){
			ans=-1;
			break;
		}
		for(j=65536;j>=a[i];j--){
			if(f[j-a[i]])f[j]^=f[j-a[i]];
		}
	}
	if(ans>=0)for(i=0;i<=65536;i++){
		if(f[i])ans^=i;
	}
	if(ans==-1)printf("0\n");
	else printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
