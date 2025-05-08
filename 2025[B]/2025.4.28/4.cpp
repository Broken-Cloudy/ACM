#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,FF;
string s;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		cin>>s;
		if(s[0]==s[n-1]){
			if(s[0]=='A')printf("Alice\n");
			else printf("Bob\n");
		}
		else{
			if(n==2){
				if(s=="AB")printf("Alice\n");
				else printf("Bob\n");
			}
			else{
				if(s[0]=='A'&&s[n-1]=='B'){
					FF=0;
					for(i=1;i<=n-2;i++){
						if(s[i]=='B')FF=1;
					}
					if(FF==1)printf("Bob\n");
					else printf("Alice\n");
				}
				else{
					if(s[n-2]=='B')printf("Bob\n");
					else  printf("Alice\n");
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
