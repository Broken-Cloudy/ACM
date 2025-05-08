#include<bits/stdc++.h>
using namespace std;
int T,i,ans,n,m,k,x,y,j;
int a[309][309];
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=k;i++){
		scanf("%d%d",&x,&y);
		a[x][y]=1;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]==1){
				if(a[i][j-1]==1&&a[i-1][j]==1)ans+=2;
				else if(a[i][j-1]==1)ans+=3;
				else if(a[i-1][j]==1)ans+=3;
				else ans+=4;
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
