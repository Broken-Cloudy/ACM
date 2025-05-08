#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,x,y,G,lcm,i,t1,t2,f[309];
void gcd(ll a,ll b){
	if(b==1){
		G=a;
		return;
	}
	gcd(b,a%b);
}
int main(){
	f[0]=1;f[1]=1;
	for(i=2;i<=100;i++){
		f[i]=f[i-1]+f[i-2];
	}
	cout<<f[41]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
