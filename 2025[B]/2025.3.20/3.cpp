#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,X;
void dfs(int L,int R){
	if(X>R){
		dfs(L*3,R*3+2);
		ans+=(R-L+1);
	}
	else ans+=(X-L+1);
	return;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	scanf("%lld",&n);ans=1;//0 3 3
	if(n==2){
		ans+=2;
	}
	else if(n>=3&&n<=5)ans+=(n-1);
	else{
		X=n;
		dfs(1,2);
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
