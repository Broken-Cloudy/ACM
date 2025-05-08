#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100009],i,GCD;
void gcd(int a,int b){
	if(b==0){
		GCD=a;
		return;
	}
	gcd(b,a%b);
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++){
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
