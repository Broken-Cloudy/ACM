#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,a[69],b[69],aa,bb;
map<int,int>M1,M2;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);aa=bb=0;M1.clear();M2.clear();
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)scanf("%lld",&b[i]);
		if(n==3)printf("NO\n");
		else{
			for(i=1;i<=n;i++){
				if(M1[a[i]]==0){
					M1[a[i]]=1;
					aa++;
				}
				if(M2[b[i]]==0){
					M2[b[i]]=1;
					bb++;
				}
			}
			if(aa==1&&bb==1)printf("NO\n");
			else if(aa==1&&bb==2)printf("NO\n");
			else if(bb==1&&aa==2)printf("NO\n");
			else printf("YES\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
