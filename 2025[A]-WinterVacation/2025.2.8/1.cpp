#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,b;
char c;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	scanf("%lld %c",&n,&c);
	if(c=='*'){
		a=n;b=1;
	}
	else if(c=='-'){
		a=2*n;b=n;
	}
	else{
		a=n-1;b=1;
	}
	cout<<a<<' '<<b<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
