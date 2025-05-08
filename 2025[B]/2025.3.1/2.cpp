#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,k,a[300009],maxx,ans;
char c[300009];
bool check(int x){
	int i,anss=0,now=9999999999LL;
	for(i=1;i<=n;i++){
		if(c[i]=='R'){
			now=max(now,a[i]);
		}
		else{
			if(a[i]<=x)continue;
			if(now>x){
				anss++;
				now=0;
			}
		}
	}
	if(anss<=k)return 1;
	else return 0;
}
void dfs(int l,int r){
	if(l==r){
		ans=l;
	}
	else if(l+1==r){
		if(check(l))ans=l;
		else ans=r;
	}
	else{
		int mid=(l+r)/2;
		if(check(mid))dfs(l,mid);
		else dfs(mid,r);
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);getchar();
		for(i=1;i<=n;i++)c[i]=getchar();maxx=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]),maxx=max(maxx,a[i]);
		dfs(0,maxx);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
