#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,l1,r1,l2,r2,ans;
void DFS(ll start,ll end,ll L,ll R,ll i,ll j){
	if(end<L||start>R||j<0)return;
	else if(start>=L&&end<=R){
		ans+=(1LL<<abs(i-j));
	}
	else{
		int mid=(start+end)/2;
		DFS(start,mid,L,R,i,j-1);
		DFS(mid,end,L,R,i,j-1);
	}
}
void dfs(ll start,ll end,ll L,ll R,ll i){
	if(end<L||start>R||i<0)return;
	else if(start>=L&&end<=R){
		DFS(0,1048576,l2,r2,i,20);
	}
	else{
		int mid=(start+end)/2;
		dfs(start,mid,L,R,i-1);
		dfs(mid,end,L,R,i-1);
	}
}
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		ans=0;
		dfs(0,1048576,l1,r1,20);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
