#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y,a;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&x,&y,&a);
		a%=(x+y);
		if(a<x){
			printf("NO\n");
		}
		else if(a>=x&&a<x+y){
			printf("YES\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
