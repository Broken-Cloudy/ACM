#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353LL;
int T,n,m,A,B,i,cur,ji,ans;
int ksm(int a,int p){
	int kk=1;
	while(p>1){
		if(p%2==0){
			a*=a;a%=P;
		}
		else{
			kk*=a;kk%=P;
			a*=a;a%=P;
		}
		p/=2;
	}
	kk*=a;kk%=P;
	return kk;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&m,&A,&B);
		ji=1;ans=0;//A
		while(ji<A){
			ji*=2LL;
			cur=min(ji/2LL-1LL,A-ji/2LL);
			ans+=(cur+1LL)*cur/2LL;
		}
		cout<<ans<<endl;
		ji=1;ans=0;//B
		while(ji<B){
			ji*=2LL;
			cur=min(ji/2LL-1LL,B-ji/2LL);
			ans+=(cur+1LL)*cur/2LL;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
