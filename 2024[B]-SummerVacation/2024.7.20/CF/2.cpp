#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y,a[100009],i;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld%lld",&n,&x,&y);
		for(i=1;i<=x;i++){
			a[i]=1;
		}
		for(i=n;i>=y;i--){
			a[i]=1;
		}
		for(i=y-1;i>=1;i-=2){
			a[i]=-1;
		}
		for(i=x+1;i<=n;i+=2){
			a[i]=-1;
		}
		for(i=1;i<=n;i++){
			if(i==n)printf("%lld\n",a[i]);
			else printf("%lld ",a[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

