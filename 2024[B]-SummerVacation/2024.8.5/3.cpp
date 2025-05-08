#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,a[59],now,i,fu,f,j;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&x);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=200;i++){
			now=0;fu=i;f=1;
			while(now<x){
				fu--;
				now++;
				if(fu<0){
					f=-1;
					break;
				}
				for(j=1;j<=n;j++)if(a[j]==now)fu=i;
			}
			while(now>0){
				fu--;
				now--;
				if(fu<0){
					f=-1;
					break;
				}
				for(j=1;j<=n;j++)if(a[j]==now)fu=i;
			}
			if(f==1)break;
		}
		printf("%lld\n",i);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
