#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXX=6e5+9;
int T,n,k,a[MAXX],j,i;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		j=1;
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)a[i]=0;
		for(i=k;i<=n;i+=k){
			a[i]=j;j++;
		}
		for(i=1;i<=n;i++){
			if(a[i]==0){
				a[i]=j;j++;
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
