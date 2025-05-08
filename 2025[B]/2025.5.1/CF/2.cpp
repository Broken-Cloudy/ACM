#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,n,x,k,i,ans;
int FF;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&x);FF=0;k=0;
		if(x==0&&n==1)FF=-1;
		for(i=0;i<=31;i++){
			if((1<<i)&x)k++;
		}
		if(FF==-1)printf("%lld\n",FF);
		else if(n<=k)printf("%lld\n",x);
		else if(x==0){
			if(n%2==1){
				ans=n+3;
			}
			else ans=n;
			printf("%lld\n",ans);
		}
		else{
			if((n-k)%2==1){
				for(i=0;i<=31;i++){
					if(((1<<i)&x)==0){
						ans=2*(1<<i);
						break;
					}
				}
				if(k>=2)printf("%lld\n",(n-k)+x+1);
				else printf("%lld\n",(n-k-1)+x+ans);
			}
			else{
				printf("%lld\n",(n-k)+x);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
