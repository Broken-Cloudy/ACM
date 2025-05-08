#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[109][109],f[109][109],k,i,j,m,T,S;
signed main(){
	//freopen("3.in","r",stdin);fclose("3.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%lld",&a[i][j]);
				f[i][j]=0;
			}
		}
		S=a[1][1];f[1][1]=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(a[i][j]==S){
					if(f[i][j-1]){
						f[i][j]=1;
					}
					if(f[i-1][j]){
						f[i][j]=1;
					}
				}
			}
		}
		if(f[n][m])cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	//fclose(stdin);fclose(stdout);
	return 0;
}
