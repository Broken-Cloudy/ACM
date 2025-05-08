#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n;
double X,ans,a[200009],l,k,kk,x,L,R,t,ANS;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lf%lf",&n,&k,&l);
		for(i=1;i<=n;i++)scanf("%lf",&a[i]);
		ans=a[1];X=k;
		for(i=2;i<=n;i++){
			L=a[i]-ans;R=a[i]+ans;
			if(X<L){
				ans+=(L-X)/2.0;
				X+=(k+(L-X)/2.0);
			}
			else if(L<=X&&X<=R){
				X+=k;
			}
			else{
				X=R+k;
			}
		}
		ans+=max(0.0,l-X);
		ans*=2.0;
		printf("%.0lf\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
