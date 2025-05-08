#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,n,i,a[200009],ans,now,ff,ANS;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		ans=1;ff=0;now=a[1];
		for(i=2;i<=n;i++){
			if(ff==0){
				if(a[i]<now){
					ff=1;
				}
				now=a[i];
			}
			else{
				if(a[i]>now){
					ans++;
					ff=0;
				}
				now=a[i];
			}
		}
		ANS=1;ff=0;now=a[n];
		for(i=n-1;i>=1;i--){
			if(ff==0){
				if(a[i]<now){
					ff=1;
				}
				now=a[i];
			}
			else{
				if(a[i]>now){
					ANS++;
					ff=0;
				}
				now=a[i];
			}
		}
		printf("%lld\n",min(ANS,ans));
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
