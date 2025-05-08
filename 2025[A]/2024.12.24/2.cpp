#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,d,i,k,L,R,ans,cc[13];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
    cin>>T;
    while(T--){
		scanf("%lld%lld",&n,&d);
		cc[1]=1;cc[3]=cc[5]=cc[7]=cc[9]=0;
		if(n>=3||d%3==0)cc[3]=1;
		if(d==5)cc[5]=1;
		if(n>=3||d==7)cc[7]=1;
		if(n>=6||n>=3&&d%3==0||d==9)cc[9]=1;
		for(i=1;i<=9;i+=2){
			if(cc[i]==1)printf("%lld ",i);
		}
		printf("\n");
	}
    fclose(stdin);fclose(stdout);
    return 0;
}
