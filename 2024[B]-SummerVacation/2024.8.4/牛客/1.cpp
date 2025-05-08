#include<bits/stdc++.h>
#define int long long
using namespace std;
char c;
int ans;
signed main(){
	while(c!=-1){
		c=getchar();
		if(c=='o')ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
