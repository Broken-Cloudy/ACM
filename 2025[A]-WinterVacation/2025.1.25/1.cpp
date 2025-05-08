#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,m,n,i,a[200009],b[200009],sum1,sum2;
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
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);FF=1;M.clear();sum1=sum2=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]),sum1+=a[i],M[a[i]]++;
		for(i=1;i<=m;i++)scanf("%lld",&b[i]),sum2+=b[i];
		if(sum1!=sum2){
			printf("No\n");
			continue;
		}
		for(i=1;i<=m;i++){
			dfs(b[i]);
		}
		if(FF==1)printf("Yes\n");
		else printf("No\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
