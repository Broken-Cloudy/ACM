#include<bits/stdc++.h>
#define int long long
#define mod 1000000007LL
using namespace std;
string s;
int T,len,i,k,ans,ANS;
map<int,int>m;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;
		len=s.length();
		ans=0;k=0;ANS=0;
		m.clear();
		for(i=0;i<len;i++){
			m[k]+=(i+1);
			if(s[i]=='1')k++;
			else k--;
			ans+=m[k];
			ans%=mod;
			ANS=ANS+ans;
			ANS%=mod;
		}
		printf("%lld\n",ANS%mod);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
