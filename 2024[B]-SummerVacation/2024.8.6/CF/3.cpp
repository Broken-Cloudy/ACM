#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int x,y;
};
nod a[200009];
bool cmp(nod x,nod y){
	return x.x<y.x;
}
int T,n,s,m,i,ans;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&s,&m);
		for(i=1;i<=n;i++)scanf("%lld%lld",&a[i].x,&a[i].y);
		sort(a+1,a+1+n,cmp);ans=0;
		for(i=1;i<=n;i++){
			if(i==1){
				ans=max(ans,a[i].x);
			}
			else{
				ans=max(ans,a[i].x-a[i-1].y);
			}
		}
		ans=max(ans,m-a[n].y);
		if(ans>=s)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
