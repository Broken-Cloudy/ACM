#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,n,cnt,T,l,i,anss;
struct nod{
	int l,a;
}b[1000009];
map<int,int>M;
bool cmp(nod x,nod y){
	return x.l>y.l;
}
double ANS;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);M.clear();cnt=0;
		for(i=1;i<=n;i++){
			scanf("%lld%lld",&l,&a);
			if(M[l]==0){
				M[l]=++cnt;
				b[cnt].l=l;
				b[cnt].a=a;
			}
			else{
				b[M[l]].a+=a;
			}
		}
		sort(b+1,b+1+cnt,cmp);
		anss=0;
		for(i=1;i<=cnt;i++){
			if(b[i].a>=2){
				anss=b[i].l;
				b[i].a-=2;
				break;
			}
		}
		ANS=-1;
		for(i=1;i<=cnt;i++){
			if(b[i].l<anss*2&&b[i].a>0){
				double a1,a2,a3;
				a1=anss;a2=anss;a3=b[i].l;
				ANS=sqrt(a1*a1-a3*a3/4.0)*0.5*a3;
				break;
			}
		}
		if(ANS<=0)printf("-1\n");
		else printf("%.9lf\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
