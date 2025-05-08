#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k1,k2,a[500009],i,pow2[63],ans,r;
int b[1000009],L=1,R;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>k1>>k2;
	if(k1>=62)k1=62;
	if(k2>=62)k2=62;
	pow2[0]=1;
	for(i=1;i<=62;i++)pow2[i]=pow2[i-1]*2;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	b[++R]=a[1];
	for(i=2;i<=n;i++){
		if((a[i]^b[R])>=pow2[k2]){
			L=R+1;
			r=0;
			b[++R]=a[i];
		}
		else{
			if((a[i]^b[R])>=pow2[k1]){
				r=(R-L+1);
				ans+=r;
			}
			else{
				ans+=r;
			}
			b[++R]=a[i];
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
