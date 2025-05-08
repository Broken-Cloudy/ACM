#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a,b,k,gcd,A,B,i,j;
void GCD(int a,int b){
	if(b==0){
		gcd=a;
	}
	else GCD(b,a%b);
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&A,&B,&k);
		a=max(A,B);b=min(A,B);
		if(a<=100000LL){
			GCD(a,b);
		}
		else{
			for(i=1;i*i<=a;i++){
				if(a%i==0){
					j=a/i;
					
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
