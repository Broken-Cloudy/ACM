#include<bits/stdc++.h>
#define ll long long
using namespace std;
double c,d,h,w,ans;
int T,i;
int main(){
	freopen("12.in","r",stdin);freopen("12.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lf%lf%lf%lf",&c,&d,&h,&w);
		ans=6*w*c/2;
		printf("%.4lf\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
