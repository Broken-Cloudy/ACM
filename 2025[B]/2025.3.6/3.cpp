#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&x,&y);
		y-=1;
		if((x-y)%9==0&&x>=y)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
