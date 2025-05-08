#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y,a[200009],sum,L,R,ans,i,ll,hh;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
    cin>>T;
    while(T--){
		scanf("%lld%lld%lld",&n,&x,&y);ans=0;sum=0;
	    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	    for(i=1;i<=n;i++)sum+=a[i];
	    L=sum-y;
		R=sum-x;
	    sort(a+1,a+1+n);
	    for(i=1;i<n;i++){
	        ll=L-a[i];hh=R-a[i];
	        int left=lower_bound(a+i+1,a+1+n,ll)-a;
	        int right=upper_bound(a+i+1,a+1+n,hh)-a;
	        ans+=(right-left);
	    }
	    printf("%lld\n",ans);	
	}
    fclose(stdin);fclose(stdout);
    return 0;
}
