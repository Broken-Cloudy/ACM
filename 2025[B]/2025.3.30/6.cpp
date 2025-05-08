#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int bh,val;
}ans[209];
bool cmp(node x,node y){
	if(x.val==y.val)return x.bh<y.bh;
	else return x.val<y.val;
}
int N,M,n,j,i,x,y,val,T,vis[209],a[209][209];
int k[209],ff,anss;
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>N>>M;
	for(i=0;i<=N;i++)for(j=0;j<=N;j++)a[i][j]=9998244353LL;
	for(i=1;i<=M;i++){
		scanf("%lld%lld%lld",&x,&y,&val);
		a[x][y]=min(a[x][y],val);a[y][x]=min(a[y][x],val);
	}
	cin>>T;
	for(i=1;i<=T;i++){
		scanf("%lld",&n);ff=1;
		memset(vis,0,sizeof(vis));
		for(j=1;j<=n;j++){
			scanf("%lld",&k[j]);
			vis[k[j]]++;
		}
		for(j=1;j<=N;j++){
			if(vis[j]!=1){
				ff=0;
				break;
			}
		}
		if(ff==1){
			int ks=0;
			ks+=a[0][k[1]];
			ks+=a[k[n]][0];
			for(j=1;j<n;j++){
				ks+=a[k[j]][k[j+1]];
			}
			if(ks<9998244353LL){
				anss++;
				ans[anss].bh=i;ans[anss].val=ks;
			}
		}
	}
	sort(ans+1,ans+1+anss,cmp);
	cout<<anss<<endl;
	cout<<ans[1].bh<<' '<<ans[1].val<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
