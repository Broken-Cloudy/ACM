#include<bits/stdc++.h>
using namespace std;
long long n,a[100009],i,ans,num[100009],k;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	num[1]=a[1]-1;ans+=num[1];
	for(i=2;i<n;i++){
		k=min(a[i],a[i+1])-1;
		k=min(k,a[i]-num[i]-1);
		num[i]+=k;num[i+1]+=k;
		ans+=k;
	}
	if(n>1)ans+=a[i]-num[i]-1;//i==n
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
