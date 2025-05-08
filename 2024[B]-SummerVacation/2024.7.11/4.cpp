#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100009],n,i,j,b[1009],ans;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=n;i>=1;i--){
		for(j=1;j<=1000;j++){
			if(a[i]%(j*j)==0){
				ans+=b[j];
			}
			if((j*j)>a[i])break;
		}
		if(a[i]<=1000)b[a[i]]++;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
