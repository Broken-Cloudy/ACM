#include<bits/stdc++.h>
#define int long long
using namespace std;
double x=8.0/9.0,t,t0,ans;
signed main(){
//	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	while(true){
		cin>>t;
		t0=1.399159;
		ans=sqrt(t/t0-x);
		printf("%.9lf\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
