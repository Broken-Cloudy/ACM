#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[200009],b[200009];
bool f;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);f=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)b[i]=0;
		for(i=1;i<=n;i++){
			if(i!=1){
				if(a[i]==1){
					if(b[2]==0){
						f=1;
						break;
					}
				}
				else if(a[i]==n){
					if(b[n-1]==0){
						f=1;
						break;
					}
				}
				else{
					if(b[a[i]-1]==0&&b[a[i]+1]==0){
						f=1;
						break;
					}
				}
			}
			b[a[i]]=1;
		}
		if(f==1)printf("NO\n");
		else printf("YES\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
