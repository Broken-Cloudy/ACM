#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1009],k,i,j,w,ans,num;
signed main(){
	//freopen("2.in","r",stdin);fclose("2.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n-k+1;i++){
		num=0;
		for(j=i,w=i+k-1;j<w;j++,w--){
			if(a[j]!=a[w])num++;
		}
		if(num==1)ans++;
	}
	cout<<ans<<endl;
	//fclose(stdin);fclose(stdout);
	return 0;
}
