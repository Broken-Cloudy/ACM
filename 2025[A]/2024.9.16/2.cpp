#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100009],GCD,i,n;
double xx,p,ans,xi;
void gcd(int a,int b){
	if(b==0){
		GCD=a;
		return;
	}
	else gcd(b,a%b);
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	GCD=a[1];
	for(i=2;i<=n;i++){
		gcd(GCD,a[i]);
	}
	xi=GCD*GCD;p=GCD;
	for(i=1;i<=n;i++){
		xi+=a[i]*a[i];
		p+=a[i];
	}
	xx=p/(n+1);
	xx=xx*xx*(n+1);
	ans=(xi-xx)/(n+1);
	printf("%.2lf\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
