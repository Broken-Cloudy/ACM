#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,m,a[109],ans;
string s;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);ans=0;
		for(i=1;i<=n;i++){
			cin>>s;
			a[i]=s.length();
		}
		for(i=1;i<=n;i++){
			if(a[i]>m){
				break;
			}
			else{
				m-=a[i];
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
