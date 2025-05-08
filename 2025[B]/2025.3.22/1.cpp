#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,k;
char c[109];
bool FF;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);getchar();
		for(i=1;i<=n;i++)c[i]=getchar();
		if(n==1){
			printf("NO\n");
			continue;
		}
		FF=0;
		if(k==0){
			for(i=1;i<=n/2;i++){
				if(c[i]<c[n-i+1]){
					FF=1;
					break;
				}
				else if(c[i]>c[n-i+1]){
					FF=0;
					break;
				}
			}
		}
		else if(k==1){
			if(c[1]!=c[n])FF=1;
			for(i=2;i<=n;i++){
				if(c[i]>c[1]){
					FF=1;
					break;
				}
			}
			for(i=1;i<n;i++){
				if(c[i]<c[n]){
					FF=1;
					break;
				}
			}
		}
		else{
			for(i=2;i<=n;i++){
				if(c[i]!=c[i-1]){
					FF=1;
					break;
				}
			}
		}
		if(FF==1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
