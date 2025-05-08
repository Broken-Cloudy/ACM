#include<bits/stdc++.h>
using namespace std;
const long double gold=(sqrtl(5.0)+1.0)/2.0;
long long w,x,y,z,a,b;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>a>>b;
	x=min(a,b);y=max(a,b);z=y-x;
	w=(long long)(gold*(long double)z);
	if(x==w){
		cout<<0<<endl;
	}
	else{
		cout<<1<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
