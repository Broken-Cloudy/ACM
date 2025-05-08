#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,q,kk,a[100009],cnt[100009],i,res[100009],ans,x;
bool check(int i,int x){//i是所需中位数,x是现在检测的模数 
	int k,ans=0;
	for(k=0;k*x<=n;k++){//log(N)
		ans+=cnt[min(k*x+i,n)]-cnt[max(0LL,k*x-1)];
	}
	if(ans>=(n+2)/2)return 1;
	else return 0;
}
void dfs(int l,int r,int x){//二分查找最小中位数 
	int mid=(l+r)/2;
	if(l==r){
		ans=l;
		return;
	}
	else if(l+1==r){
		if(check(l,x)){
			ans=l;
		} 
		else ans=r;
		return;
	}
	else{
		if(check(mid,x)){
			dfs(l,mid,x);
		}
		else dfs(mid,r,x);
		return;
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&q);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			cnt[a[i]]++;
		}
		for(i=1;i<=n;i++){//数组数前缀和 
			cnt[i]+=cnt[i-1];
		}
		for(x=1;x<=n;x++){//O(N)
			dfs(0,x,x);//O(logN)
			res[x]=ans;
		}
		while(q--){
			scanf("%lld",&kk);
			if(q>0)printf("%lld ",res[kk]);
			else printf("%lld\n",res[kk]);
		}
		for(i=1;i<=n;i++)cnt[i]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
