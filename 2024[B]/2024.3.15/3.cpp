#include<bits/stdc++.h>
using namespace std;
const __int128 inf=998244353;
__int128 l1,l2,l3,l4,A,B,X;
long long T,i,a,b,x,L1,L2,L3,L4;
int main(){
    freopen("3.in","r",stdin);freopen("3.out","w",stdout);
    cin>>T;
    for(int o=1;o<=T;o++){
    	scanf("%lld%lld%lld",&a,&b,&x);
    	A=a;B=b;X=x;
    	l1=A*X+B;
    	l2=(X+1)*X*A/2;l2+=B*X;
    	l3=A*(X+1)*(X+2)*X/6;
		l3%=inf;l3+=B*(X+1)*(X)/2;
    	l4=X*(X+1)*(X+2)*(X+3)/24;l4%=inf;l4*=A;
    	l4+=B*(X+1)*(X+2)*X/6;
		l1%=inf;l2%=inf;l3%=inf;l4%=inf;
		L1=l1;L2=l2;L3=l3;L4=l4;
		printf("%lld %lld %lld %lld\n",L1,L2,L3,L4);
	}
    fclose(stdin);fclose(stdout);
    return 0;
}
