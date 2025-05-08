#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,m,n,i,a[200009],b[200009];
bool FF;
map<int,int>M;
void dfs(int x){
	if(FF==0)return;
	if(x==0){
		FF=0;
		return;
	}
	if(M[x]>0){
		M[x]--;
		return;
	}
	else{
		if(x%2==0){
			dfs(x/2);
			dfs(x/2);
		}
		else{
			dfs(x/2);
			dfs(x/2+1);
		}
	}
}
signed main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);FF=1;M.clear();
		for(i=1;i<=n;i++)scanf("%lld",&a[i]),M[a[i]]++;
		for(i=1;i<=m;i++)scanf("%lld",&b[i]);
		for(i=1;i<=m;i++){
			dfs(b[i]);
		}
        for(i=1;i<=n;i++)if(M[a[i]])FF=0;
		if(FF==1)printf("Yes\n");
		else printf("No\n");
	}
//	fclose(stdin);fclose(stdout);
	return 0;
}
