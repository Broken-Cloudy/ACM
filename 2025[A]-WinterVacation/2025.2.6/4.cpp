#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,k,n,m,a[1009][1009],x,y,ans;
int b[1009][1009],c[1009][1009],ANS;
void dfs1(int x,int y){
	int i,j,kk=0;
	i=x;j=y;
	while(i<=n&&j<=m){
		kk+=a[i][j];
		i++;j++;
	}
	i=x;j=y;
	while(i<=n&&j<=m){
		b[i][j]=kk;
		i++;j++;
	}
}
void dfs2(int x,int y){
	int i,j,kk=0;
	i=x;j=y;
	while(i<=n&&j>=1){
		kk+=a[i][j];
		i++;j--;
	}
	i=x;j=y;
	while(i<=n&&j>=1){
		c[i][j]=kk;
		i++;j--;
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);ANS=0;
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)b[i][j]=c[i][j]=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		i=1;
		for(j=1;j<=m;j++){
			dfs1(i,j);
		}
		j=1;
		for(i=1;i<=n;i++){
			dfs1(i,j);
		}
		i=1;
		for(j=1;j<=m;j++){
			dfs2(i,j);
		}
		j=m;
		for(i=1;i<=n;i++){
			dfs2(i,j);
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				ans=0;
				ans+=b[i][j];ans+=c[i][j];
				ans-=a[i][j];
				ANS=max(ANS,ans);
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
