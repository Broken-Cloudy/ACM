#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,a[200009],vis[200009],p[200009],ans,ANS;
int L,R,l,r;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;ANS=0;L=0;R=-1;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			vis[i]=0;p[i]=0;
		}
		for(i=1;i<=n;i++){
			if(vis[a[i]]==0)vis[a[i]]=i;
			else{
				p[vis[a[i]]]=1;p[i]=1;
			}
		}
		for(i=1;i<=n;i++){
			if(p[i]==0){
				ans++;
			}
			else{
				if(ans>=ANS){
					l=i-ans;
					r=i-1;
					if((r-l)>(R-L)){
						R=r;L=l;
					}
				}
				ans=0;
			}
		}
		if(ans>=ANS){
			l=i-ans;
			r=i-1;
			if((r-l)>(R-L)){
				R=r;L=l;
			}
		}
		if(R-L<0)printf("0\n");
		else printf("%lld %lld\n",L,R);
	}
	fclose(stdin);fclose(stdout);
}
