#include<bits/stdc++.h>
using namespace std;
long long T,i,n,a[200009],ans1[200009],ans2[200009],ans3,sum;
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ans3=a[n];
	for(i=1;i<=n-2;i++){
		ans1[i]=ans1[i-1]^a[i];
	}
	for(i=n-1;i>=2;i--){
		ans2[i]=ans2[i+1]|a[i];
	}
	for(i=2;i<n;i++){
		sum=max(sum,ans1[i-1]+ans2[i]+ans3);
	}
	cout<<sum<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
