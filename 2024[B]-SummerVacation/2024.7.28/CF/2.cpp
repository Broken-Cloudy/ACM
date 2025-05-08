#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[100009],b[100009],i;
int f=0;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);f=0;
		for(i=0;i<=n+1;i++)b[i]=0,a[i]=0;
		for(i=1;i<n;i++)scanf("%lld",&b[i]);
		a[1]=b[1];
		for(i=2;i<=n;i++){
			a[i]=(b[i]|b[i-1]);
		}
		for(i=1;i<n;i++){
			if((a[i]&a[i+1])!=b[i]||a[i]==(1<<30)){
				f=1;
				break;
			}
		}
		if(f==1){
			printf("-1\n");
			continue;
		}
		for(i=1;i<=n;i++){
			if(i==n){
				printf("%lld\n",a[i]);
			}
			else{
				printf("%lld ",a[i]);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
