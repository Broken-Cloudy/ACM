#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n;
double Y,ans,a[200009],l,k,kk,x,L,R,t,ANS,cc,ss;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lf%lf",&n,&k,&l);
		for(i=1;i<=n;i++)scanf("%lf",&a[i]);
		Y=l;ans=a[1];ANS=(Y-k)+ans;
		for(i=n;i>=2;i--){
			L=a[i]-ans;R=a[i]+ans;
			kk=(n-i)*k-(l-Y);//Ê£ÓàÕÛµþ³¤¶È 
			cc=max(0.0,(Y-k));
			if(kk>=cc/2.0)cc/=2.0;
			else{
				ss=cc/2.0-kk;
				cc=ss*2.0+kk;
			}
			ANS=min(ANS,cc+ans);
			if(L<=Y-k&&Y-k<=R){
				Y=Y-k;
			}
			else if(L>Y-k){
				Y=L;
			}
			else{
				t=((Y-k)-R)/2.0;
				if(t>kk){
					ans+=kk;
					Y-=kk;R+=kk;
					t-=kk;
					ans+=t*2.0;
					Y=Y-k-kk;
				}
				else{
					ans+=t;
					Y=Y-k-t*2.0;
				}
			}
		}
		ANS*=2.0;
		printf("%.0lf\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
