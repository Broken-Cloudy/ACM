#include<bits/stdc++.h>
using namespace std;
int a[5009],n,m,i,l,r,f[5009][5009],j,ANS;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			f[i][j]=f[i][j-1]^(a[i]+a[j]);
		}
	}
	for(i=1;i<=m;i++){
		ANS=0;
		scanf("%d%d",&l,&r);
		for(j=l;j<=r;j++){
			ANS^=(f[j][r]);
		}
		cout<<ANS<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
