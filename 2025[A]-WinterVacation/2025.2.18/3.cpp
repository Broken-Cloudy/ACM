#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=998244353LL;
int T,a[200009],i,n,C3[200009],ANS,PP,SS;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ANS=0;
		for(i=0;i<=n+1;i++)C3[i]=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=n;i>=1;i--){
			if(a[i]==3)C3[i]=C3[i+1]+1;
			else C3[i]=C3[i+1];
		}
		SS=0;PP=0;
		for(i=1;i<=n;i++){
			if(a[i]==2){
				PP*=2;PP+=SS;SS=0;
				PP%=INF;
				ANS+=(PP*C3[i]);
				ANS%=INF;
			}
			else if(a[i]==1){
				SS++;
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
}
