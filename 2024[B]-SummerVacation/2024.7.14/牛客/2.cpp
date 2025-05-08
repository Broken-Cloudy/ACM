#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,j,len,k;
string s[120];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>s[i];
	for(i=1;i<=n;i++){
		len=s[i].length();
		for(j=0;j<len;j++){
			k+=s[i][j]-'0';
		}
	}
	if(k%3==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
