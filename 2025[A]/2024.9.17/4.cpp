#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100009],c,i,maxx,ans;
bool check(int x){
	int i,kk=0,nowa=a[1];
	for(i=2;i<n;i++){
		if(a[i]-nowa>=x&&a[n]-a[i]>=x){
			nowa=a[i];
		}
		else{
			kk++;
		}
	}
	if(kk>c)return 0;
	else return 1;
}
void dfs(int l,int r){
	int i;
	if(l==r){
		ans=l;
	}
	else if(l==r-1){
		if(check(r))ans=r;
		else ans=l;
	}
	else{
		int mid=(l+r)/2;
		if(check(mid))dfs(mid,r);
		else dfs(l,mid);
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n>>c;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	maxx=a[n]-a[1];
	dfs(1,maxx);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
