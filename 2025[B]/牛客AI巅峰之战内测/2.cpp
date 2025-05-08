#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[100009],x,y;
bool FF;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		FF=1;//RED
		if(n>=3){
			x=0;//Å¼ÊýÓ® 
			for(i=1;i<=n;i++){
				if(a[i]>=a[i-1]&&a[i]>=a[i+1]){
					break;
				}
				else x++;
			}
			y=0;//Å¼ÊýÓ® 
			for(i=n;i>=1;i--){
				if(a[i]>=a[i-1]&&a[i]>=a[i+1]){
					break;
				}
				else y++;
			}
			if(x%2==1&&y%2==1)FF=0;
		}
		if(FF==1)printf("RED\n");
		else printf("PURPLE\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
