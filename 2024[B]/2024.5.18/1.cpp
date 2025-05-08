#include<bits/stdc++.h>
using namespace std;
double x,n,y,ans;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>x>>y;
	ans=(n/x)*y-n;
	printf("%.4lf\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
