#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,k,q,aa,c[100009],m,K,x,d,l,r,t;
vector<int>a[100009];
vector<int>b[100009];
char ch;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	scanf("%lld%lld%lld",&n,&k,&q);//n是国家 k是流域 
	for(i=1;i<=n;i++){
		a[i].push_back(0);
		for(j=1;j<=k;j++){
			scanf("%lld",&aa);
			a[i].push_back(aa);
		}
	}
	for(i=1;i<=k;i++){
		c[1]=a[1][i];
		for(j=2;j<=n;j++){
			c[j]=a[j][i]|c[j-1];
		}
		b[i].push_back(0);
		for(j=1;j<=n;j++){
			b[i].push_back(c[j]);
		}
		b[i].push_back(10000000000009LL);
	}
	while(q--){
		scanf("%lld",&m);l=1;r=n;
		for(i=1;i<=m;i++){
			scanf("%lld %c %lld",&K,&ch,&x);
			d=upper_bound(b[K].begin()+1,b[K].end(),x)-(b[K].begin());
			t=lower_bound(b[K].begin()+1,b[K].end(),x)-(b[K].begin());
			if(ch=='>'){
				l=max(l,d);
			}
			else{
				r=min(r,t-1);
			}
		}
		if(l<=r)printf("%lld\n",l);
		else printf("-1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
