#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,c1,c0,i,r;
char c;
bool f=0;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		c1=c0=0;f=0;
		scanf("%lld",&n);getchar();
		for(i=1;i<=n;i++){
			c=getchar();
			if(c=='1')c1++;
			else c0++;
		}
		r=sqrt(n);
		if(r*r==n){
			if(c1==(4*r-4)&&c0==(n+4-4*r))f=1;
		}
		if(f==1)printf("Yes\n");
		else printf("No\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
