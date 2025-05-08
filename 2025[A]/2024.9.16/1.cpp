#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
char c[12];
int i;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(i=0;i<len;i++){
		c[i]=((s[i]-'0'+3)%10+'0');
	}
	for(i=0;i<len;i++){
		cout<<c[i];
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
