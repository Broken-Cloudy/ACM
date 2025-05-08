#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
bool f;
int i,len,sum;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>s;sum=1;
	len=s.length();
	for(i=0;i<len;i++){
		if(s[i]=='-')sum--;
		else sum*=2;
		if(sum>=2025){
			f=1;
		}
	}
	if(f==1)printf("YES\n");
	else printf("NO\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
