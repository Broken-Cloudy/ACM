#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,l,r,G,L,R,i,GCD,j,k;
bool FF;
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	else return gcd(b,a%b);
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&l,&r,&G);
		L=(l+(G-1))/G;R=r/G;
		if(L>R){
			printf("-1 -1\n");
		}
		else{
			FF=0;
			for(i=R-L;i>=0;i--){
				for(j=L;j+i<=R;j++){
					k=j+i;
					if(gcd(j,k)==1||j==1&&k==1){
						FF=1;
						break;
					}
				}
				if(FF==1)break;
			}
			if(FF==1)printf("%lld %lld\n",j*G,k*G);
			else printf("-1 -1\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
