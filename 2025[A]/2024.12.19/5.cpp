#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,i,j,a[2009][1009];
bool FF=0;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);FF=0;
		for(i=1;i<=2*n;i++){
			for(j=1;j<=m;j++){
				a[i][j]=((i+j)%(2*n))/2+1;
			}
		}
		if(m>2*n-1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
			for(i=1;i<=2*n;i++){
				for(j=1;j<=m;j++){
					printf("%lld ",a[i][j]);
				}
				printf("\n");
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
