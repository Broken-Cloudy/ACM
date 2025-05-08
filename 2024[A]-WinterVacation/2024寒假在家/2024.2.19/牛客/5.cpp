#include<bits/stdc++.h>
using namespace std;
long long n,a[200009],i,ans,k,sum[200009],h=1,j;
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		//a[i]%=k;
		sum[i]=sum[i-1]+a[i];
	}
	for(i=1;i<=n;i++){
		for(j=h;j<=i;j++){
			long long r=sum[i]-sum[j-1];
			if(r<k)break;
			else{
				if(r%k==0){
					ans++;
					h=i+1;
				}
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
