#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,xx,yy,T,i,j,cnt;
char c,a[809][809];
bool ff=0;
void solve(){
	int i,j;
	printf("Yes\n");
	for(i=1;i<=n;i++){//µã 
		for(j=1;j<=m;j++){
			putchar(a[i][j]);
		}
		putchar('\n');
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld%lld",&n,&m,&k);
		scanf("%lld%lld",&xx,&yy);
		getchar();c=getchar();
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if((i+j)%2==0){
					a[i][j]='A';
				}
				else a[i][j]='B';
			}
		}
		if(a[xx][yy]!=c){
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					if((i+j)%2==0){
						a[i][j]='B';
					}
					else a[i][j]='A';
				}
			}
		}
		cnt=0;
		for(i=1;i<=n+1;i++){//µã 
			for(j=1;j<=m+1;j+=2){
				if(j==1){
					if(i==n+1&&a[i-1][j]=='B'){
						j=1;
					}
					else if(i<=n&&a[i][j]=='A')j=1;
					else j=2;
				}
				cnt++;
			}
		}
		if(cnt<k){
			printf("No\n");
			continue;
		}
		ff=0;
		for(i=1;i<=n;i++){
			if(ff==1)break;
			for(j=m;j>=1;j--){
				if(cnt==k){
					solve();
					ff=1;
					break;
				}
				if(a[i][j]=='A'){
					if(i>=1&&j>=1&&i<n&&j<m){
						if(i==xx&&j==yy)a[i][j+1]='A';
						else a[i][j]='B';
						cnt--;
					}
				}
				if(cnt==k){
					solve();
					ff=1;
					break;
				}
			}
		}
		if(ff==0){
			printf("No\n");
			continue;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

