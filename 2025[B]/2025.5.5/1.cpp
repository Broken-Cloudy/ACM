#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int bh,val;
}a[109];
bool cmp(nod x,nod y){
	return x.val<y.val;
}
bool cmp2(nod x,nod y){
	return x.bh<y.bh;
}
int T,i,n,kk,FF;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);FF=0;
		for(i=1;i<=n;i++){
			a[i].bh=i;
			scanf("%lld",&a[i].val);
		}
		sort(a+1,a+1+n,cmp);
		kk=a[n].val;a[n].val=2;
		for(i=n-1;i>=1;i--){
			if(a[i].val!=kk){
				FF=1;a[i].val=1;
			}
			else a[i].val=2;
		}
		if(FF==0)printf("No\n");
		else{
			sort(a+1,a+1+n,cmp2);
			printf("Yes\n");
			for(i=1;i<=n;i++){
				if(i==n)printf("%lld\n",a[i].val);
				else printf("%lld ",a[i].val);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
