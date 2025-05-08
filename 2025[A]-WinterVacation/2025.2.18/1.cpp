#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,N,a[109];
bool FF;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>N;FF=1;N-=2;
		for(i=1;i<=N;i++){
			scanf("%lld",&a[i]);
		}
		if(N<=2){
			printf("YES\n");
			continue;
		}
		else{
			for(i=1;i<=N-2;i++){
				if(a[i]==1&&a[i+1]==0&&a[i+2]==1){
					FF=0;break;
				}
			}
		}
		if(FF==1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
}
