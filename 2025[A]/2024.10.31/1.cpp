#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,vis[200009],ans[200009],cnt,i,ANS;
bool f;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);f=0;ANS=0;
		for(i=1;i<=n;i++)vis[i]=0;
		if(n==5){
			printf("5\n");
			printf("2 1 3 4 5\n");
		}
		else if(n%2==0){
			cnt=n;
			for(i=(1LL<<20);i>=5;i=(i>>1)){
				if(i&n||f==1){
					f=1;
					ans[cnt]=i;cnt--;vis[i]=1;
					ans[cnt]=i-1;cnt--;vis[i-1]=1;
				}
			}
			vis[1]=vis[2]=vis[3]=vis[4]=vis[5]=1;
			ans[cnt]=4;cnt--;ans[cnt]=3;cnt--;
			ans[cnt]=2;cnt--;ans[cnt]=5;cnt--;ans[cnt]=1;cnt--;
			cnt=0;
			for(i=1;i<=n;i++){
				if(vis[i]==0){
					ans[++cnt]=i;
				}
			}
			for(i=1;i<=n;i++){
				if(i%2)ANS=ANS&ans[i];
				else ANS=ANS|ans[i];
			}
			printf("%lld\n",ANS);
			for(i=1;i<=n;i++){
				if(i==n)printf("%lld\n",ans[i]);
				else printf("%lld ",ans[i]);
			}
		}
		else{
			cnt=n;
			ans[cnt]=n;cnt--;vis[n]=1;
			for(i=(1LL<<20);i>=5;i=(i>>1)){
				if(i&n||f==1){
					f=1;
					ans[cnt]=i;cnt--;vis[i]=1;
					ans[cnt]=i-1;cnt--;vis[i-1]=1;
				}
			}
			vis[1]=vis[2]=vis[3]=vis[4]=vis[5]=1;
			ans[cnt]=4;cnt--;ans[cnt]=3;cnt--;
			ans[cnt]=2;cnt--;ans[cnt]=5;cnt--;ans[cnt]=1;cnt--;
			cnt=0;
			for(i=1;i<=n;i++){
				if(vis[i]==0){
					ans[++cnt]=i;
				}
			}
			for(i=1;i<=n;i++){
				if(i%2)ANS=ANS&ans[i];
				else ANS=ANS|ans[i];
			}
			printf("%lld\n",ANS);
			for(i=1;i<=n;i++){
				if(i==n)printf("%lld\n",ans[i]);
				else printf("%lld ",ans[i]);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
