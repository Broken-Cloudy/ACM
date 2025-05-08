#include<bits/stdc++.h>
using namespace std;
int n,m,a[109][20009],i,j,ANS,sum;
int main(){
	freopen("10.in","r",stdin);freopen("10.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=m;i++){
		sum=0;
		for(j=1;j<=n;j++){
			sum+=a[j][i];
		}
		ANS=max(ANS,sum);
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
