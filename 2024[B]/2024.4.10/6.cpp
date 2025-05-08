#include<bits/stdc++.h>
using namespace std;
struct nod{
	int st,ed;
};
bool cmp(nod x,nod y){
	if(x.st==y.st){
		return x.ed<y.ed;
	}
	else{
		return x.st<y.st;
	}
}
nod a[209];
//dp[i][j][k],其中i表示前i个,j表示覆盖两次的到j,k表示覆盖一次的到k。 
int n,m,i,j,k,dp[209][209][209];
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		scanf("%d%d",&a[i].st,&a[i].ed);
	}
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			for(k=j;k<=n;k++){
				if(a[i].st<=j){
					dp[i][min(a[i].ed,k)][max(a[i].ed,k)]+=dp[i-1][j][k];
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
