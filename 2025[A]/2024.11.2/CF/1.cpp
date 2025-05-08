#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[59],j;
bool ff,f;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ff=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<n;i++){
			j=i+1;
			if(max(a[i],a[j])-min(a[i],a[j])!=5&&max(a[i],a[j])-min(a[i],a[j])!=7){
				ff=1;
			}
		}
		if(ff==1)printf("NO\n");
		else printf("YES\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
