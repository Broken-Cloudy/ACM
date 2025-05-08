#include<bits/stdc++.h>
using namespace std;
double a,b,c,ans;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>a>>b>>c;
	ans=c*a/b-a;
	printf("%.4lf\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
