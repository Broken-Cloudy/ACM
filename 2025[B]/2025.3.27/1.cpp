#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353LL;
int T,n,m,A,B,i,ans,poi,n_2,m_2,ans1,ans2,k1,k2,ANS;
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
		n_2=(ksm(2,n)-2+P)%P;
		m_2=(ksm(2,m)-2+P)%P;
		ans=0;ans1=0;ans2=0;
		for(poi=0;poi<=29;poi++){
			if((1LL<<poi)&A){
				k1=(A>>(poi+1))*(1LL<<poi)+(1LL+A%(1LL<<poi));
			}
			else{
				k1=(A>>(poi+1))*(1LL<<poi);
			}
			if((1LL<<poi)&B){
				k2=(B>>(poi+1))*(1LL<<poi)+(1LL+B%(1LL<<poi));
			}
			else{
				k2=(B>>(poi+1))*(1LL<<poi);
			}
			k1%=P;k2%=P;
			ans+=k1*k2%P*(1LL<<poi)%P;
			ans1+=k1*(1LL<<poi)%P;//Õë¶ÔA 
			ans2+=k2*(1LL<<poi)%P;//Õë¶ÔB 
			ans%=P;ans1%=P;ans2%=P;
		}
		ans=ans*n_2%P*m_2%P;
		ans1=ans1*n_2%P*(B+1)%P;
		ans2=ans2*m_2%P*(A+1)%P;
		ANS=(A+1)*(B+1)%P;
		ANS=(ANS+ans+ans1+ans2)%P;
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
