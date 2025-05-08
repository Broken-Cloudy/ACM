#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,i,j,k;
char c[1009][1009],d[1009][1009];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&n,&k);
		getchar();
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				c[i][j]=getchar();
			}
			getchar();
		}
		for(i=1;i<=n;i+=k){
			for(j=1;j<=n;j+=k){
				if(k==1)d[i/k][j/k]=c[i][j];
				else d[i/k+1][j/k+1]=c[i][j];
			}
		}
		for(i=1;i<=n/k;i++){
			for(j=1;j<=n/k;j++){
				putchar(d[i][j]);
			}
			putchar('\n');
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
