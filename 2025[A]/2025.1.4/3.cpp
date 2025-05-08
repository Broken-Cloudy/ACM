#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,l,r,ans,changecnt,a,b,c,maxcnt,p[65],ss,b1,c1;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&l,&r);a=b=c=0LL;maxcnt=-1;
		for(i=35;i>=1;i--){
			p[i]=0;
			if((l&(1LL<<(i-1)))||(r&(1LL<<(i-1)))){
				if(maxcnt==-1)maxcnt=i;
				p[i]=1;
			}
			if((l&(1LL<<(i-1)))!=(r&(1LL<<(i-1)))){
				changecnt=i;
				break;
			}
		}
		for(i=maxcnt;i>=1;i--){
			if(i>changecnt){
				if(p[i]==1){
					a+=(1LL<<(i-1));
					b+=(1LL<<(i-1));
					c+=(1LL<<(i-1));	
				}	
				else{
					continue;
				}
			}
			else if(i==changecnt){
				a+=(1LL<<(i-1));
			}
			else{
				b+=(1LL<<(i-1));
			}
		}
		if(b-1>=l)c=b-1;
		else c=a+1;
		printf("%lld %lld %lld\n",a,b,c);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
