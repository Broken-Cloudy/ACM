#include<bits/stdc++.h>
#define int long long
using namespace std;
bool f=1;
int n,i,a[100009],ans,cur;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(i=2;i<=n;i++){
		if(a[i]!=a[i-1])f=0;
	}
	if(f==1){
		printf("0\n");
	}
	else if(a[1]>0){
		printf("-1\n");
	}
	else{
		cur=1;ans=1;
		for(i=2;i<=n;i++){
			if(a[i]-a[i-1]>=2){
				ans+=(a[i]-cur);
			}
			cur=a[i]+1;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
