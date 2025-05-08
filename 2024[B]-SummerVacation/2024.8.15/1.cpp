#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=998244353;
int a,b,x,y,ans;
int k,r;
void exgcd(long long a,long long b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;y=t-(a/b)*y;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>a>>b;
	k=a+b;
	exgcd(k,inf);//1/k
	ans=((x%inf)*(a%inf)%inf+inf)%inf;
	cout<<ans<<' ';
	ans=((x%inf)*(b%inf)%inf+inf)%inf;
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
