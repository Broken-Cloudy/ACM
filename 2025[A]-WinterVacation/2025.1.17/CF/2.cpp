#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
char c[1009][1009];
int T,i,j,n,pai[1009],a[1009];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			getchar();
			pai[i]=0;
			for(j=1;j<=n;j++){
				c[i][j]=getchar();
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i>j){
					if(c[i][j]=='1'){
						pai[i]++;
					}
				}
				else if(i==j){
					pai[i]++;
				}
				else{
					if(c[i][j]=='0'){
						pai[i]++;
					}
				}
			}
		}
		for(i=1;i<=n;i++)a[pai[i]]=i;
		for(i=1;i<=n;i++)printf("%lld ",a[i]);
		putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
