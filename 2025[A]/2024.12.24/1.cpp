#include<bits/stdc++.h>
#define int long long
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
#define sc(x) tree[x].s
using namespace std;
int T,n,i,k,L,R,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    cin>>T;
    while(T--){
		scanf("%lld",&n);ans=1;
		while(n>3){
			ans*=2;
			n/=4;
		}
		printf("%lld\n",ans);
	}
    fclose(stdin);fclose(stdout);
    return 0;
}
