#include<iostream>
#include<cstdio>
using namespace std;
long long a,b,c;
double d,e;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
    cin>>a>>b>>c>>d>>e;
    d/=100.0;e/=100.0;
    long long ans=(a+b+c)*(1+d)*(e);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
