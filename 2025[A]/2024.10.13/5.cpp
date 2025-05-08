#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,i,j,m,r,l,ans,R,D,rr,dd;
char c[100009];
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>q;getchar();
	for(i=1;i<=n;i++){
		c[i]=getchar();
		if(c[i]=='r')R++;
		else if(c[i]=='d')D++;
	}
	while(q--){
		scanf("%lld%lld",&l,&r);
		ans=0;rr=0;dd=0;
		for(i=l,j=r;i<j;i++,j--){
			swap(c[i],c[j]);
		}
		for(i=1;i<=n;i++){
			if(c[i]=='r')rr++;
			else if(c[i]=='d')dd++;
			else{
				ans+=rr*(D-dd);
			}
		}
		for(i=l,j=r;i<j;i++,j--){
			swap(c[i],c[j]);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
