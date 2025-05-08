#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y,kk;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&x,&y);
		kk=abs(x+(x+1)-y);
		if(kk%4==0){
			printf("YES\n");
		}
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
