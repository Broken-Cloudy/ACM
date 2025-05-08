#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1000000007LL;
int T,i,n,m,k,x,y,cc,r,abc,B,W,rr,ANS;
int ksm(int a,int p){
	if(p<=0)return 1LL;
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
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		r=(n-2LL)*(m-2LL)+4LL;B=W=0;
		rr=2LL*n+2LL*(m-2LL)-4LL;//四条边-四个角 
		for(i=1;i<=k;i++){
			scanf("%lld%lld%lld",&x,&y,&cc);
			if(x>1&&x<n&&y>1&&y<m){
				r--;
			}
			else if(x==1&&y==1||x==1&&y==m||x==n&&y==1||x==n&&y==m){
				r--;
			}
			else{
				rr--;
				if(cc==0)B++;
				else W++;
			}
		}
		abc=ksm(2,r);
		if(B%2==1&&W%2==1&&rr==0){
			ANS=0;
		}
		else{
			ANS=ksm(2,rr-1);
		}
		ANS*=abc;ANS%=P;
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
