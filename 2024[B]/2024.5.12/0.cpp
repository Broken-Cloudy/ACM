#include<bits/stdc++.h>
using namespace std;
int n,m,a[109][20009],i,j,ANS,sum;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else return gcd(b,a%b);
}
int x,y,GCD;
int main(){
	//freopen("0.in","r",stdin);freopen("0.out","w",stdout);
	cin>>x>>y;
	GCD=gcd(x,y);
	x/=GCD;y/=GCD;
	cout<<x<<' '<<y<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
