#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,m,F,k,f1,f2;
char c[59][59];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++){
			getchar();
			for(j=1;j<=m;j++){
				c[i][j]=getchar();
			}
		}
		F=1;
		for(i=2;i<=n;i++){
			for(j=2;j<=m;j++){
				if(c[i][j]=='1'){
					f1=1;f2=1;
					for(k=1;k<=i;k++){
						if(c[k][j]=='0')f1=0;
					}
					for(k=1;k<=j;k++){
						if(c[i][k]=='0')f2=0;
					}
					F=min(F,(f1|f2));
				}
			}
		}
		if(F==1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
