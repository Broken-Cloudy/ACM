#include<bits/stdc++.h>
#define int long long
using namespace std;
int V,E,K,i,T,j,ans;
bool FF;
map<int,int>M;
int a[509][509],x,y,b[509];
signed main(){
	freopen("125.in","r",stdin);freopen("125.out","w",stdout);
	cin>>V>>E>>K;
	for(i=1;i<=E;i++){
		scanf("%lld%lld",&x,&y);
		a[x][y]=1;a[y][x]=1;
	}
	cin>>T;
	while(T--){
		FF=1;
		for(i=1;i<=V;i++)scanf("%lld",&b[i]);M.clear();ans=0;
		for(i=1;i<=V;i++){
			if(M[b[i]]==0){
				M[b[i]]=1;
				ans++;
			}
		}
		if(ans!=K){
			printf("No\n");
			continue;
		}
		for(i=1;i<=V;i++){
			for(j=i+1;j<=V;j++){
				if(a[i][j]==1&&a[j][i]==1){
					if(b[i]==b[j]){
						FF=0;
						break;
					}
				}
			}
			if(FF==0)break;
		}
		if(FF==1)printf("Yes\n");
		else printf("No\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
