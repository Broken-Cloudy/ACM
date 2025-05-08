#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,m,k,a[100009],cnt,ans,b[100009];
map<int,int>M;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);M.clear();cnt=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			if(M[a[i]]==0){
				cnt++;
				M[a[i]]=cnt;
				b[cnt]=1;
			}
			else{
				b[M[a[i]]]++;
			}
		}
		sort(b+1,b+1+cnt);ans=cnt;
		for(i=1;i<=cnt;i++){
			if(k>=b[i]){
				k-=b[i];
				ans--;
			}
			else break;
		}
		ans=max(1LL,ans);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
