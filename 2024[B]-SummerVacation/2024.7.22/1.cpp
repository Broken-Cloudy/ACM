#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18+9;
int T,k,n,a[200009],i,j,f[200009][5];
int l,r,x;
int abss(int x){
	return max(x,-x);
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			f[i][0]=inf;f[i][1]=inf;f[i][2]=inf;f[i][3]=inf;
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n==1){
			if(a[1]==0)printf("%lld\n",0LL);
			else printf("%lld\n",1LL);
			continue;
		}
		else{
			if(a[1]==0){
				f[1][0]=0;
			}
			else if(a[1]>=1&&a[1]<=2){
				f[1][0]=1;f[1][1]=1;
			}
			else if(a[1]>=3&&a[1]<=4){
				f[1][0]=1;f[1][3]=2;
			}
			else{
				f[1][0]=1;
			}
		}
		for(i=2;i<=n;i++){
			if(a[i]==0){
				f[i][0]=min(f[i][0],f[i-1][0]);
				f[i][0]=min(f[i][0],f[i-1][1]);
				f[i][0]=min(f[i][0],f[i-1][2]);
				f[i][0]=min(f[i][0],f[i-1][3]);
			}
			else if(a[i]<=2&&a[i]>=1){
				f[i][0]=min(f[i][0],f[i-1][0]+1);
				f[i][0]=min(f[i][0],f[i-1][1]+1);
				f[i][0]=min(f[i][0],f[i-1][2]+1);
				f[i][0]=min(f[i][0],f[i-1][3]+1);//main
				f[i][0]=min(f[i][0],f[i-1][1]);
				f[i][0]=min(f[i][0],f[i-1][3]);
				f[i][1]=min(f[i][1],f[i-1][0]+1);
			}
			else if(a[i]>=3&&a[i]<=4){
				f[i][0]=min(f[i][0],f[i-1][0]+1);
				f[i][0]=min(f[i][0],f[i-1][1]+1);
				f[i][0]=min(f[i][0],f[i-1][2]+1);
				f[i][0]=min(f[i][0],f[i-1][3]+1);//main
				f[i][0]=min(f[i][0],f[i-1][3]);
				f[i][1]=min(f[i][1],f[i-1][2]+1);
				f[i][2]=min(f[i][2],f[i-1][1]+1);
				f[i][3]=min(f[i][3],f[i-1][0]+2);
			}
			else{
				f[i][0]=min(f[i][0],f[i-1][0]+1);
				f[i][0]=min(f[i][0],f[i-1][1]+1);
				f[i][0]=min(f[i][0],f[i-1][2]+1);
				f[i][0]=min(f[i][0],f[i-1][3]+1);//main
			}
		}
		printf("%lld\n",min(f[n][0],min(f[n][1],min(f[n][2],f[n][3]))));
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
