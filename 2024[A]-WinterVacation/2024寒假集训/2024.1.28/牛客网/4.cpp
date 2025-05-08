#include<bits/stdc++.h>
using namespace std;
long long x,y,l,r,k;
long long ans1,ans2;
void gcd(long long a,long long b){
	if(b==0){
		k=a;
		return;
	}
	gcd(b,a%b);
}
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>x>>y>>l>>r;
	if(y>x)swap(x,y);
	gcd(x,y);
	x/=k;y/=k;
	swap(x,y);//x–° y¥Û 
	if(l%x==0)ans1=l/x;
	else ans1=l/x+1;
	ans2=r/y;
	if(ans2<ans1)cout<<0<<endl;
	else cout<<ans2-ans1+1<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
