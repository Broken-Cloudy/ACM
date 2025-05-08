#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500009],L,R,n,i,num[500009];
bool cmp(ll x,ll y){
	return x>y;
}
set<int>ss;
int main(){
	freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	cin>>n>>L>>R;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]=(a[i]+1)/2;
	} 
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++){
	} 
	fclose(stdin);fclose(stdout);
	return 0;
} 
