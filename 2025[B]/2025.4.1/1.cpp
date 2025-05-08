#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,mini,i,j,a[200009],b[200009],n,p[63],maxx,k;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		mini=1000000000000000001LL;
		for(i=1;i<=n;i++){
			scanf("%lld",&b[i]);
			mini=min(mini,b[i]);
		}
		p[0]=1;
		for(i=1;i<=63;i++){
			if(1000000000000000001LL/mini<p[i-1]){
				p[i]=1000000000000000001LL;
				maxx=i;//要除以几次 
				break;
			}
			p[i]=p[i-1]*mini;
		}
		for(i=1;i<=n;i++){
			
			for(j=i-1;j>=max(1LL,i-63);j++){
				
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
