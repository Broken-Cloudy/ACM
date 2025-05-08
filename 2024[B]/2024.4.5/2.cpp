#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y,ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&x,&y);
		int t=min(x,y);
		x-=t;
		y-=t;
		if(y==0){
			if(x%3==0){
				printf("Yes\n");
			}
			else printf("No\n");
		}
		else if(x==0){
			if(y%3==0){
				printf("Yes\n");
			}
			else printf("No\n");
		}
		else{
			printf("No\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
