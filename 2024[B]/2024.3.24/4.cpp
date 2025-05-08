#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[100009],i,b[100009],ans;
bool f=0;
bool cmp(int x,int y){
	return x>y;
}
int jue(int x){
	return max(x,-x);
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n-1;i++){
		b[i]=jue(a[i+1]-a[i]);
	}
	sort(b+1,b+n,cmp);
	for(i=1;i<n;i++){
		int t=b[i];
		if(t>=k)f=1;
		if(t>k){
			ans+=(t-1)/k;
		}
	}
	if(ans==0&&f==0){
		cout<<1<<endl;
	}
	else cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
