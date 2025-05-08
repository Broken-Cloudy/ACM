#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,t,a[200009],i,f[200009];
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&t);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+1+n);
		t-=n;
		if(t<0){
			printf("0\n");
		}
		else{
			f[1]=0;
			for(i=1;i<=n;i++){
				
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
