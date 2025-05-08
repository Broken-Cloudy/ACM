#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],n,i,j,f[1010][1010];
int main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(a[i]==b[j]){
				f[i][j]=max(f[i][j],f[i-1][j-1]+1);
			}
		}
	}
	cout<<f[n][n]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
