#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a,b,c[100009],i,maxx,ans,GCD,d[100009];
void gcd(int a,int b){
	if(b==0){
		GCD=a;
		return;
	}
	else gcd(b,a%b);
}
bool check(int x,int G){
	int maxx,D;
	for(i=1;i<=n;i++){
		d[i]=c[i]%G;
	}
	sort(d+1,d+1+n);
	D=d[n]-d[1];maxx=d[n];
	for(i=1;i<n;i++){
		D=min(D,d[i]+G-d[i+1]);
		maxx=max(maxx,d[i]+G);
	}
	if(D>x)return 0;
	else return 1;
}
void dfs(int l,int r,int G){
	int mid=(l+r)/2;
	if(l==r){
		ans=l;
		return;
	}
	else if(l+1==r){
		if(check(l,G)){
			ans=l;
		}
		else ans=r;
		return;
	}
	else{
		if(check(mid,G)){
			dfs(l,mid,G);
		}
		else dfs(mid,r,G);
		return;
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&a,&b);
		for(i=1;i<=n;i++)scanf("%lld",&c[i]);
		sort(c+1,c+1+n);
		gcd(a,b);
		dfs(0,c[n]-c[1],GCD);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
