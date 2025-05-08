#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,n,T,j,m,k;
int a[509][509],b[509][509];
char c;
bool f;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		f=0;
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++){
			getchar();
			for(j=1;j<=m;j++){
				c=getchar();
				a[i][j]=c-48;
			}
		}
		for(i=1;i<=n;i++){
			getchar();
			for(j=1;j<=m;j++){
				c=getchar();
				b[i][j]=c-48;
			}
		}
		for(i=1;i<=n-1;i++){
			for(j=1;j<=m-1;j++){
				k=(b[i][j]-a[i][j]+3)%3;
				a[i][j]=(a[i][j]+k)%3;
				a[i+1][j+1]=(a[i+1][j+1]+k)%3;
				a[i][j+1]=(a[i][j+1]+2*k)%3;
				a[i+1][j]=(a[i+1][j]+2*k)%3;
			}
		}
		for(i=1;i<=n;i++){
			if(a[i][m]!=b[i][m]){
				f=1;
				break;
			}
		}
		for(i=1;i<=m;i++){
			if(a[n][i]!=b[n][i]){
				f=1;
				break;
			}
		}
		if(f==1){
			printf("NO\n");
		}
		else printf("YES\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
