#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,j,a[509][509],ans;
int work(int x,int y){
	int i=x;
	int j=y;
	int ANS=0;
	while(i<=n&&j<=n){
		ANS=min(ANS,a[i][j]);
		i++;j++;
	}
	return abs(ANS);
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		for(i=1;i<=n;i++){
			ans+=work(1,i);
		}
		for(i=2;i<=n;i++){
			ans+=work(i,1);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
