#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,k,a[200009];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		if(n%2==0){
			printf("-1\n");
			continue;
		}
		else if(n%2==1){
			k=n;
			for(i=1;i<=n/2+1;i++){
				a[i]=k;
				k-=2;
			}
			k=n-1;
			for(i=n;i>n/2+1;i--){
				a[i]=k;
				k-=2;
			}
		}
		else{
			k=n;
			for(i=1;i<=n/2;i++){
				a[i]=k;
				k--;
			}
			k=n;k/=2;
			for(i=n;i>n/2;i--){
				a[i]=k;
				k--;
			}
		}
		for(i=1;i<=n;i++){
			if(i!=n)printf("%lld ",a[i]);
			else printf("%lld\n",a[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
