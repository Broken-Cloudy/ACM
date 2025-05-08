#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXX=6e5+9;
int T,n,m,a[MAXX],b[MAXX],i,k,j,P[MAXX],my,d,ans,mypoi;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=m;i++)scanf("%lld",&b[i]);
		my=a[1];sort(a+2,a+1+n);sort(b+1,b+1+m);
		mypoi=upper_bound(b+1,b+1+m,my)-(b+1);
		for(i=1;i<=m;i++){
			d=lower_bound(a+2,a+1+n,b[i])-(a+1);
			j=n-d+1;P[i]=j;
		}
		for(k=1;k<=m;k++){
			ans=0;j=0;
			for(i=1;i<=m;i+=k){
				if(i+k-1>mypoi){
					j=mypoi-i+1;
					break;
				}
				else{
					ans+=1;
				}
			}
			for(i=m+j;i>=1;i-=k){
				if(i-k+1<=mypoi){
					break;
				}
				else{
					ans+=P[i-k+1];
				}
			}
			if(k!=m)printf("%lld ",ans);
			else printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
