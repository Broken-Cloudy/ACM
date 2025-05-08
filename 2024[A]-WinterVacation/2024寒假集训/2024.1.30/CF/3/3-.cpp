#include<bits/stdc++.h>
using namespace std;
long long T,i,n,m,a,b,r,d[68],j,A[68],B[68],work[68],ans,D,power[65];
int main(){
	freopen("3-.in","r",stdin);freopen("3-.out","w",stdout);
	cin>>T;
	power[0]=1;power[1]=2;
	for(i=2;i<=62;i++)power[i]=power[i-1]*2;
	for(long long o=1;o<=T;o++){
		scanf("%lld%lld%lld",&a,&b,&r);
		long long k=max(a,b),cnt=0,c=a,d=b;
		while(k>0){
			k=k>>1;cnt++;
		}
		D=max(a-b,b-a);
		for(j=0;j<=cnt;j++){
			ans=0;a=c;b=d;
			for(i=cnt-j;i>=0;i--){
				k=power[i];
				if(ans+k<=r){
					if(max((a^k)-(b^k),(b^k)-(a^k))<D){
						D=max((a^k)-(b^k),(b^k)-(a^k));
						a^=k;b^=k;
						ans+=k;
					}
				}
			}
		}
		printf("%lld\n",D);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
