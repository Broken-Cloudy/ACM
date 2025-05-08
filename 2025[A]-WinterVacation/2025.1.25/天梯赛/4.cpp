#include<bits/stdc++.h>
using namespace std;
int n,m,k,kk,i,j,x,y,ans,Q;
map<int,map<int,int>>M;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		for(j=1;j<=k;j++){
			scanf("%d",&kk);
			M[i][kk]=1;
		}
	}
	cin>>Q;
	while(Q--){
		scanf("%d%d",&x,&y);ans=0;
		for(i=1;i<=n;i++){
			if(M[i][x]==1&&M[i][y]==1){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
