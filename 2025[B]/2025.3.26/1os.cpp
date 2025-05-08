#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,k,op,n,m,cha,last,p,q,r,s,K[109];
map<int,map<int,map<int,map<int,int>>>>M;
signed main(){
	freopen("1os.in","r",stdin);freopen("1os.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;memset(K,0,sizeof(K));
		M.clear();
		for(k=0;k<=n+20;k++){
			for(p=0;p<=n;p++){
				for(q=p;q<=n;q++){
					if((p^q)==k){
						K[k]++;
					}
				}
			}
		}
		for(i=0;i<=n+20;i++){
			if(i==n+20)printf("%lld\n",K[i]);
			else printf("%lld ",K[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
