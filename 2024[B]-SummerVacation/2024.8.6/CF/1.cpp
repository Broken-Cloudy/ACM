#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,i;
string s;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;ans=0;
		int len=s.length();
		for(i=0;i<len;i++){
			ans+=(s[i]-'0');
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
