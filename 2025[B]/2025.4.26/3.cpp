#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[100009],i,f,ff,abc;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(n<=3){
			printf("No\n");
			continue;
		}
		sort(a+1,a+1+n);f=0;ff=0;i=1;
		while(i<=n){
			if(a[i]==a[i+1]&&i<n){
				if(f==1){
					if(a[i]==abc||a[i]==abc+1)ff=1;
					else{
						f=1;
						abc=a[i];
					}
				}
				else{
					f=1;
					abc=a[i];
				}
				i+=2;
			}
			else{
				if(f==1){
					if(a[i]==a[i-1]+1||a[i]==a[i-1]){
						abc=a[i];
					}
					else f=0;
				}
				i++;
			}
		}
		if(ff==1)printf("Yes\n");
		else printf("No\n");
		for(i=1;i<=n;i++)a[i]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
