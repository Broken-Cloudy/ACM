#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,j,n;
double x[10009],y[10009],dis=1e10;
double DIS(int i,int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lf%lf",&x[i],&y[i]);
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			dis=min(dis,DIS(i,j));
		}
	}
	printf("%.4lf\n",dis);
	fclose(stdin);fclose(stdout);
	return 0;
}
