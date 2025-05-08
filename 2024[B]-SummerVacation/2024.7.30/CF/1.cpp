#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,k;
string s;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;
		int len=s.length();
		if(len==1){
			if(s[0]=='z')s+='a';
			else s+='z';
			cout<<s<<endl;
			continue;
		}
		k=-1;
		for(i=1;i<len;i++){
			if(s[i]==s[i-1]){
				k=i;
				break;
			}
		}
		if(k==-1){
			if(s[0]=='z')putchar('a');
			else putchar('z');
			cout<<s<<endl;
		}
		else{
			for(i=0;i<len;i++){
				if(i==k){
					if(s[i-1]=='z')putchar('a');
					else putchar('z');
					putchar(s[i]);
				}
				else putchar(s[i]);
			}
			putchar('\n');
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
