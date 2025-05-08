#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int a,c;
};
nod fl[200009];
int T,n,m,i,ans;
bool cmp(nod x,nod y){
	return x.a<y.a;
}
int work(int a,int x,int b,int y){
	int ANS,r;
	if(a*x+b*y<=m){
		return a*x+b*y;
	}
	else{
		if(b*y>=m){//讨论大数字 
			int k1,k2;
			k2=(m+(b-1))/b;//向上取整
			k1=x;
			r=(m+(b-1))/b*b;r=r-m;//差值
			if(k1>=r&&k2>=r){
				return m;
			} 
			else{
				return m/b*b;
			}
		}
		else{
			int k1,k2;
			r=b*y;
			k1=x-(m-r+(a-1))/a;k2=0;
			r=r+(m-r+(a-1))/a*a;r-=m;//差值
			if(y>=r&&k1>=r){
				return m;
			}
			else{
				return b*y+(m-b*y)/a*a;
			}
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%lld",&fl[i].a);
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&fl[i].c);
		}
		sort(fl+1,fl+1+n,cmp);ans=0;
		for(i=1;i<=n;i++){
			if(fl[i].a==fl[i+1].a-1&&i!=n){
				ans=max(ans,work(fl[i].a,fl[i].c,fl[i+1].a,fl[i+1].c));
			}
			ans=max(ans,min(fl[i].a*fl[i].c,m/fl[i].a*fl[i].a));
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
