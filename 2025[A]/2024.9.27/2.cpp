#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1000000007;
int n,m,ans=1,i,T;
int Pow2[1000009];
void Pre(){
	Pow2[0]=1;
	for(i=1;i<=1000000;i++)Pow2[i]=(Pow2[i-1]*2)%inf;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;Pre();
	while(T--){
		ans=1;
		cin>>n>>m;
		for(i=1;i<=n;i++){
			ans*=(Pow2[m]-2+inf)%inf;ans%=inf;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
