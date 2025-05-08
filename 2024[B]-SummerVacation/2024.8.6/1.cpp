#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500009],i,T,maxx,ans,b[500009],f[500009],ANS;
bool check(int x){
	int i;
	b[0]=0;
	for(i=1;i<=n;i++){
		if(a[i]<x)b[i]=-1;
		else b[i]=1;
		f[i]=0;
	}
	for(i=1;i<=n;i++){
		if(i%k==1){
			if(i-k>=0)f[i]=max(f[i-k],b[i]);//建造消除片段 
		}
		else{
			f[i]=f[i-1]+b[i];//向后移动消除片段 
			if(i-k>=0)f[i]=max(f[i-k],f[i]);//消除这一段 
		}
	}
	if(f[n]>0)return 1;
	else return 0;
}
void solve(int l,int r){
	if(l==r){
		ans=l;
	}
	else if(l+1==r){
		if(check(r)){
			ans=r;
		}
		else{
			ans=l;
		}
	}
	else{
		int mid=(l+r)/2;
		if(check(mid)){
			solve(mid,r);
		}
		else{
			solve(l,mid);
		}
	}
	return;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);maxx=0;
		if(k>=n){
			for(i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			sort(a+1,a+1+n);
			ans=a[(n+1)/2];
			printf("%lld\n",ans);
			continue;
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			maxx=max(maxx,a[i]);
		}
		solve(0,maxx);ANS=0;
		for(i=1;i<=n;i++){
			if(a[i]<=ans)ANS=max(ANS,a[i]);
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
