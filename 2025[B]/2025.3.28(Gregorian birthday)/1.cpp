#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n;
double X,Y,ans,a[200009],l,k,ANS,Z;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lf%lf",&n,&k,&l);
		for(i=1;i<=n;i++)scanf("%lf",&a[i]);
		X=0;ANS=1000000009.0;ans=0;
		for(i=1;i<=n;i++){
			Y=a[i]-ans;Z=l;
			if(X>=Z){
				ANS=min(ANS,ans);
			}
			else{
				ANS=min(ANS,ans+(Z-X));
			}
			if(X>=Y){
				if((a[i]+ans)<=X){
					X=(a[i]+ans)+k;
				}
				else{
					X=X+k;
				}
			}
			else{
				if(i==1){
					ans+=(Y-X);
					X=X+k;
				}
				else{
					ans+=(Y-X)/2.0;
					X=X+(Y-X)/2.0+k;
				}
			}
		}
		if(X>=l){
			ANS=min(ANS,ans);
		}
		else{
			ANS=min(ANS,ans+(l-X));
		}
		ANS*=2;
		printf("%.0lf\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
