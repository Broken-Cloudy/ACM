#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,a[300009],C;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);C=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			if(a[i]%2==0&&C==0){
				C=1;
			}
			else C=0;
		}
		if(C==0){
			printf("Bob\n");
		}
		else{
			printf("Alice\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
