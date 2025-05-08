#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int a,b;
};
nod a[200009];
int T,n,i,maxx,k,p,ANS;
int check(int x){
	int i,kk=0;
	for(i=1;i<=n;i++){
		kk+=(a[i].a-x+(a[i].b-1))/a[i].b;
	}
	return kk;
}
bool cmp(nod x,nod y){
	return x.a>y.a;
}
void b_s(int l,int r){
	if(l==r){
		p=l;
		return;
	}
	int mid=(l+r)/2;
	if(check(mid)>k){
		b_s(mid+1,r);
	}
	else b_s(l,mid);
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);maxx=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i].a);
			maxx=max(maxx,a[i].a);
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i].b);
		}
		b_s(0,maxx);ANS=0;
		for(i=1;i<=n;i++){
			int op=(a[i].a-p+(a[i].b-1))/a[i].b;
			int shou=a[i].a;
			int wei=shou-(op-1)*a[i].b;
			a[i].a=max(0LL,shou-op*a[i].b);
			ANS+=(shou+wei)*op/2;
			if(wei<0)ANS+=(-wei);
			k-=op;
		}
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=k;i++){
			ANS+=a[i].a;
			if(a[i].a==0)break;
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
