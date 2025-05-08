#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,ans[10009],r,k,j,bh[10009];
bool ff;
signed main(){
//	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	ans[1]=0;ans[2]=0;
	while(T--){
		scanf("%lld",&n);ff=0;
		for(i=1;i<=n;i++)bh[i]=i;
		for(i=2;i<n;i++){
			if(ff==0){
				printf("? %lld %lld\n",1LL,i);fflush(stdout);
				scanf("%lld",&r);
				if(r==1){
					ans[i]=0;
				}
				else{
					ans[i]=1;bh[1]=i;
					k=1;
					ff=1;
				}
			}
			else{
				for(j=k;j<n;j++){
					printf("? %lld %lld\n",j,i);fflush(stdout);
					scanf("%lld",&r);
					if(r==0){
						k=j;
						ans[i]=bh[j];
						bh[j]=i;
						break;
					}
					else{
						//...
					}
				}
			}
		}
		printf("! ");
		for(i=1;i<n;i++){
			if(i==n-1)printf("%lld\n",ans[i]);
			else printf("%lld ",ans[i]);
		}
		fflush(stdout);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
