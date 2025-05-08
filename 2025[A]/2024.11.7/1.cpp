#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,ans;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=10*n;i++){
			if(i%2==1){
				ans+=-(2*i-1);
			}
			else{
				ans+=(2*i-1);
			}
			if(abs(ans)>n){
				if(i%2==0){
					printf("Kosuke\n");
				}
				else{
					printf("Sakurako\n");
				}
				break;
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
