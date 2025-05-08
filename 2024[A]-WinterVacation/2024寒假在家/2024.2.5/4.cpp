#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18+9;
ll T,n,m,k,vis[5009],i,poi;
struct nod{
	int a,b;
};
bool cmp(nod x,nod y){
	return x.b<y.b;
}
nod card[1009];
void dfs(ll gcard,ll cost){
	int i;
	if(cost>vis[gcard])return;
	else{
		vis[gcard]=cost;
		for(i=1;i<=m;i++){
			dfs((gcard+card[i].a)%n,cost+card[i].b);
		}
	}
}
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld%lld",&n,&m,&k);
		for(i=0;i<=n;i++)vis[i]=INF;//³õÊ¼»¯ 
		for(i=1;i<=m;i++){
			scanf("%lld%lld",&card[i].a,&card[i].b);
		}
		poi=n-k;
		sort(card+1,card+1+m,cmp);
		dfs(0,0);
		if(vis[poi]!=INF){
			printf("%lld\n",vis[poi]);
		}
		else printf("-1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
