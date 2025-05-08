#include<bits/stdc++.h>
using namespace std;
int T,n,a[200009],i,zuo,you,ans,k1,k2;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);ans=9999999;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		zuo=a[1];you=a[n];
		for(i=2;i<=n;i++){
			if(a[i]!=zuo){
				k1=i;
				break;
			}
		}
		if(i==n+1)ans=0;
		for(i=n;i>=1;i--){
			if(a[i]!=zuo){
				k2=i;
				break;
			}
		}
		if(i==0)ans=0;
		else ans=min(ans,(k2-k1+1));
		for(i=n-1;i>=1;i--){
			if(a[i]!=you){
				k2=i;
				break;
			}
		}
		if(i==0)ans=0;
		for(i=1;i<=n;i++){
			if(a[i]!=you){
				k1=i;
				break;
			}
		}
		if(i==n+1)ans=0;
		else ans=min(ans,(k2-k1+1));
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
