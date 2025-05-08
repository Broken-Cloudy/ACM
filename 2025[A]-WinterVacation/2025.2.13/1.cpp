#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[200009],ans,j,cnt;
bool FF;
map<int,int>M;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;M.clear();
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=1;i<=n;i++){
			if(a[i]>0)ans++;
		}
		cnt=1;FF=0;
		for(i=1;i<=n;i++){
			if(a[i]==0){
				FF=1;
				for(j=n;j>i;j--){
					M[a[j]]++;
				}
				while(M[cnt]>0)cnt++;
				for(j=i-1;j>=1;j--){
					if(a[j]>=cnt){
						M[a[j]]++;
						while(M[cnt]>0)cnt++;
					}
					else{
						FF=0;
						break;
					}
				}
				break;
			}
		}
		if(FF==1)ans++;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
