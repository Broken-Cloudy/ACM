#include<bits/stdc++.h>
#define int long long
using namespace std;
bool f=1;
int n,a[100009],cnt,i,k[100009],q;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>q;
	while(q--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&k[i]);
			a[++cnt]=k[i];
		}
		for(i=1;i<n;i++){
			if(k[i]>=k[i+1])f=0;
		}
	}
	sort(a+1,a+1+cnt);
	for(i=1;i<cnt;i++){
		if(a[i+1]-a[i]!=1)f=0;
	}
	if(f==1)printf("YES\n");
	else printf("NO\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
