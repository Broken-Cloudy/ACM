#include<bits/stdc++.h>
const __int128 inf=1e18+7,mod=1e9+1;
using namespace std;
long long n,q,a[100009],i,l,r;
__int128 zhen[100009],dao[100009],ans1,ans2,powe[100009];
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n>>q;
	powe[1]=mod;
	for(i=1;i<=100000;i++)powe[i]=powe[i-1]*mod;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		zhen[i]=(zhen[i-1]*mod+a[i])%inf;
	}
	for(i=n;i>=1;i--){
		dao[i]=(dao[i+1]*mod+a[i])%inf;
	}
	for(int o=1;o<=q;o++){
		scanf("%lld%lld",&l,&r);
		if(r-l+1>=2){
			long long mid=(l+r)/2;
			ans1=(zhen[mid]+inf-zhen[l-1]*powe[mid-l+1]%inf)%inf;
			ans2=(dao[mid]+inf-dao[r+1]*powe[r-mid+1]%inf)%inf;
			if(ans1==ans2){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
		else{
			printf("NO\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
