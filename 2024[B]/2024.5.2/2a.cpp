#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1000000007;
int T,n,i;
int k,arr[100009],cnt,d,ans;
signed main(){
	freopen("2a.in","r",stdin);freopen("2a.out","w",stdout);
	cin>>T;
	while(k*k+k-1<=1000000000){
		arr[++k]=k*k+k-1;
	}
	cnt=k;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		d=upper_bound(arr+1,arr+1+cnt,n)-(arr+1);
		ans=2*d*(d+1)*(2*d+1)/3-3*d*(d+1)/2;
		ans%=inf;
		n-=arr[d];
		k=(d-1)*2+1;
		d++;//现在的状况
		if(n>d){
			k++;
			ans+=d*k;
			ans%=inf;
			k++;n-=d;
			ans+=n*k;
			ans%=inf;
		} 
		else{
			k++;
			ans+=n*k;
			ans%=inf;
		}
		ans%=inf;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
