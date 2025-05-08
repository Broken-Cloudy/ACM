#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,len,i,ans,m,cnt,bh;
struct nod{
	ll a,b,cha;
};
nod quan[100009],k,zhan[100009];
bool cmp(nod x,nod y){
	return x.a<y.a;
}
int main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&n,&m);bh=0;
		for(i=1;i<=n;i++){
			scanf("%lld%lld",&quan[i].a,&quan[i].b);
		}
		sort(quan+1,quan+1+n,cmp);
		for(i=2;i<=n;i++){
			quan[i].b+=quan[i-1].b;
		}
		for(i=1;i<=n;i++){
			quan[i].cha=quan[i].a-quan[i].b;
		}
		for(i=1;i<=n;i++){
			if(m>=quan[i].cha){
				bh=i;
			}
		}
		printf("%lld\n",m+quan[bh].b);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
