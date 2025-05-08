#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,a[100009],i,ji,ou;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<1<<endl;
	}
	else{
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]%2==0)ou++;
			else ji++;
		}
		if(ji>ou){
			ji-=ou;
			cout<<ji%2<<endl;
		}
		else if(ji==ou)cout<<0<<endl;
		else{
			cout<<ou-ji<<endl;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
