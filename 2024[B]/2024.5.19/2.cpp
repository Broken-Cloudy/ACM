#include<bits/stdc++.h>
using namespace std;
int T,i;
double x,r=180.0,ans;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(i=1;i<=T;i++){
		scanf("%lf",&x);
		ans=r/(x+1);
		printf("%.8lf\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
