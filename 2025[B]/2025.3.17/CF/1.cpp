#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int bh,val;
}b[5009];
bool cmp(nod x,nod y){
	return x.val>y.val;
}
int T,n,k,i,j,a[5009],ANS,ans,vis[5009],K,maxx,kk[5009],l,r;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		ANS=0;
		scanf("%lld%lld",&n,&K);
		for(i=1;i<=n;i++){
			vis[i]=0;
			scanf("%lld",&a[i]);
			b[i].bh=i;b[i].val=a[i];
		}
		sort(b+1,b+1+n,cmp);
		if(K>=2){
			K++;
			for(i=1;i<=n;i++){
				if(K>0){
					ANS+=b[i].val;
					K--;
				}
			}
			printf("%lld\n",ANS);
		}
		else{
			for(i=1;i<=n;i++){
				if(i!=1)ANS=max(ANS,a[i]+a[1]);
				if(i!=n)ANS=max(ANS,a[i]+a[n]);
			}
			printf("%lld\n",ANS);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
