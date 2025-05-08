#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y,ans;
bool f,ff;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&x,&y);
		ans=f=ff=0;
		if(y==0){
			printf("%lld\n",0ll);
			continue;
		}
		while(x>0){
			if(f==0){
				ans++;
				f=1;
				y-=x;
				x--;
			}
			else if(ff==0){
				ff=1;
				ans++;
				y-=x;
			}
			else{
				ff=0;
				ans++;
				y-=x;
				x--;
			}
			if(y<=0){
				printf("%lld\n",ans);
				break;
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
