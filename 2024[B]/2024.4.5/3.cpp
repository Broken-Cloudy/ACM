#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[18],cnt,ans,k,i;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		memset(a,0,sizeof(a));
		scanf("%lld",&n);
		int nn=n;
		cnt=0;ans=0;
		while(n>0){
			cnt++;
			int t=n%10;
			n/=10;
			if(t==0){
				a[cnt]=1;
			}
			else{
				a[cnt]=0;
			}
		}
		k=0;
		for(i=1;i<=cnt;i++){
			if(k==0){
				k=1;
				ans+=k*a[i];
			}
			else{
				k*=10;
				ans+=k*a[i];
			}
		}
		if(ans==0&&nn%10!=1){
			printf("1\n");
		}
		else if(ans==0&&nn%10==1){
			printf("2\n");
		}
		else printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
