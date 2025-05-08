#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353LL;
int T,n,m,A,B,ANS;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&m,&A,&B);A++;B++;
		if(B>A){
			swap(A,B);swap(n,m);
		}
		ANS=0;
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
