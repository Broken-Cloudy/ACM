#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n;
double Y,ans,a[200009],l,k,ANS,kk,x;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lf%lf",&n,&k,&l);
		for(i=1;i<=n;i++)scanf("%lf",&a[i]);
		kk=max(0.0,k-(l-a[n]));ans=max(0.0,(l-a[n])-k);
		Y=max(l-k,a[n]);ans+=a[1];a[1]=0;
		for(i=n-1;i>=1;i--){
			if(Y-a[i]<=k){
				kk+=(k-(Y-a[i]));
				Y=a[i];
			}
			else{
				x=(Y-a[i])-k;
				if(kk*2>=x){//kk £”‡—πÀı 
					kk-=x/2.0;
					ans+=x/2.0;
					Y=a[i]+x/2.0;
				}
				else{
					x-=kk;
					kk=0;
					ans+=kk/2.0;
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
