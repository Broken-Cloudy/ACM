#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,k,i,tt,ans;
char c[200009];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&x,&k);getchar();
		for(i=1;i<=n;i++)c[i]=getchar();
		tt=0;
		for(i=1;i<=n;i++){
			tt++;
			if(c[i]=='L')x--;
			else x++;
			if(x==0)break;
		}
		if(x!=0||tt>k){
			ans=0;
		}
		else{
			ans=1;k-=tt;tt=0;
			for(i=1;i<=n;i++){
				tt++;
				if(c[i]=='L')x--;
				else x++;
				if(x==0)break;
			}
			if(x==0)ans+=(k/tt);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
