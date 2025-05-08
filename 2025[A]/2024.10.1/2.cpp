#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,f[3009][3009],ans;
char c[3009][3009];
bool ff=0;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=m;j++){
			c[i][j]=getchar();
		}
	}
	for(i=1;i<=n-1;i++){
		for(j=1;j<=m-1;j++){
			if(c[i][j+1]==c[i+1][j]){
				f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+1);
				f[i+1][j]=max(f[i+1][j],f[i][j]);
				f[i][j+1]=max(f[i][j+1],f[i][j]);
				if(c[i][j+2]==c[i+1][j+1])f[i+1][j+2]=max(f[i+1][j+2],f[i][j]+2);
				if(c[i+2][j]==c[i+1][j+1])f[i+2][j+1]=max(f[i+2][j+1],f[i][j]+2);
			}
			else{
				f[i+1][j+1]=max(f[i+1][j+1],f[i][j]);
				f[i+1][j]=max(f[i+1][j],f[i][j]);
				f[i][j+1]=max(f[i][j+1],f[i][j]);
			}
		}
	}
	for(i=1;i<=n;i++)if(f[i][m]>=2)ff=1;
	for(i=1;i<=m;i++)if(f[n][i]>=2)ff=1;
	if(ff)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	/*
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cout<<f[i][j]<<' ';
		}
		cout<<endl;
	}*/
	fclose(stdin);fclose(stdout);
	return 0;
}
