#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_N=2e5+9;
int T,i,n,a[MAX_N],sumz[MAX_N],sumf[MAX_N],vis[MAX_N],ANS;
int zhen[MAX_N],fu[MAX_N],nowzhen,nowfu,cntz,cntf;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ANS=0;cntz=cntf=0;
		for(i=0;i<=n+1;i++){
			vis[i]=0;
			zhen[i]=0;
			fu[i]=0;
			sumz[i]=sumf[i]=0;
		}
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		nowfu=nowzhen=0;
		for(i=1;i<=n;i++){
			if(a[i]>0){
				cntz++;nowzhen=i;
				vis[i]=cntz;
				sumz[cntz]=sumz[cntz-1]+a[i];
			}
			else{
				fu[i]=nowzhen;
			}
		}
		for(i=n;i>=1;i--){
			if(a[i]<0){
				cntf++;nowfu=i;
				vis[i]=cntf;
				sumf[cntf]=sumf[cntf-1]+abs(a[i]);
			}
			else{
				zhen[i]=nowfu;
			}
		}
		for(i=1;i<=n;i++){
			if(a[i]>0){
				ANS=max(ANS,sumz[vis[i]]+sumf[vis[zhen[i]]]);
			}
			else{
				ANS=max(ANS,sumf[vis[i]]+sumz[vis[fu[i]]]);
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
}
