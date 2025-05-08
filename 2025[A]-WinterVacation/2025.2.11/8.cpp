#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,ANS,b[100009],kk,d;
struct nod{
	int a,b;
}a[100009];
bool cmp1(nod x,nod y){
	return x.a>y.a;
}
signed main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld%lld",&a[i].a,&a[i].b);
		sort(a+1,a+1+n,cmp1);ANS=a[1].a;
		for(i=2;i<=n;i++){
			ANS=max(ANS,a[i].a+a[i].b);
		}
		b[0]=0;b[++b[0]]=-a[1].a;
		for(i=2;i<=n;i++){
			kk=a[i].a+a[i].b;kk=-kk;
			d=lower_bound(b+1,b+1+b[0],kk)-b;
			if(d<b[0]){
				ANS=max(ANS,a[1].a+a[1].b);
				break;
			}
			else{
				b[++b[0]]=-a[i].a;
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
