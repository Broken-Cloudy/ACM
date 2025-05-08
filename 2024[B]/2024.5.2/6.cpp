#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,m,a[1000009],ans;
bool f=0;
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&n,&m);
		f=0;ans=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=1;i<=n;i++){
			ans++;
			a[i]--;
		}
		m--;//Ë«ÄÃÈ¡ 
		for(i=1;i<=n;i++){
			if(m==0){
				break;
			}
			if(a[i]>=m*2){
				ans+=m*2;
				a[i]-=m*2;
				m=0;
			}
			else{
				ans+=a[i]/2*2;
				m-=a[i]/2;
				a[i]-=a[i]/2*2;
			}
			if(m==0){
				break;
			}
		}
		m++;
		for(i=1;i<=n;i++){
			if(m==0){
				f=1;
				break;
			}
			if(a[i]>=1){
				ans++;
				m--;
				a[i]--;
			}
			if(m==0){
				f=1;
				break;
			}
		}
		if(f==0){
			printf("-1\n");
		}
		else{
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
