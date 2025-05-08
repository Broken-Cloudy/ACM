#include<bits/stdc++.h>
using namespace std;
long long i,n,j,k,a[1009],ans=-1e9-7,nowa,qishi;
bool f=0;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(k==0){
		for(i=1;i<=n;i++){
			nowa+=a[i];
			if(nowa<0){
				nowa=0;
			}
			else{
				ans=max(ans,nowa);
			}
		}
		for(i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		printf("%lld\n",ans);
	}
	else{
		qishi=1;
		for(i=1;i<=n;i++){
			nowa+=a[i];
			ans=max(ans,nowa);
			if(a[qishi+1]<0)ans=max(ans,nowa-a[i]-a[qishi+1]);
			if(a[qishi+1]<0)ans=max(ans,nowa-a[qishi+1]);
			if(a[qishi]<0)ans=max(ans,nowa-a[i]-a[qishi+1]);
			if(a[qishi]<0)ans=max(ans,nowa-a[qishi+1]);
			if(i+1<=n)ans=max(ans,nowa-a[i]+a[i+1]);//向后重选 
			if(qishi>=2)ans=max(ans,nowa+a[qishi-1]);//向前重选 
			if(qishi>=2)ans=max(ans,nowa-a[i]+a[qishi-1]);//向前重选 
			if(nowa<0){
				nowa=0;qishi=i;
			}
		}
		for(i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
