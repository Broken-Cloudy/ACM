#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int a,b;
};
nod a[200009];
int T,n,k,i,ans;
bool cmp1(nod x,nod y){
	if(x.b==y.b)return x.a>y.a;
	else return x.b>y.b;
}
bool cmp2(nod x,nod y){
	return x.a<y.a;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)scanf("%lld",&a[i].a);
		for(i=1;i<=n;i++)scanf("%lld",&a[i].b);
		sort(a+1,a+1+n,cmp1);
		if(a[1].b==1){
			a[1].a+=k;
			sort(a+1,a+1+n,cmp2);
			ans=a[n/2].a+a[n].a;
			//»¹Ô­
			sort(a+1,a+1+n,cmp1); 
			a[1].a-=k;
			
		}
		else{
			sort(a+1,a+1+n,cmp2);
			ans=a[n/2].a+a[n].a;
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
