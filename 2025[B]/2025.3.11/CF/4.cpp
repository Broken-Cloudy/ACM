#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,x[200009],r[200009],i,j,ans,y,l;
map<int,int>M;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);M.clear();
		for(i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(i=1;i<=n;i++)scanf("%lld",&r[i]);
		for(i=1;i<=n;i++){
			for(j=x[i]-r[i];j<=x[i]+r[i];j++){
				l=abs(x[i]-j);
				y=sqrtl(r[i]*r[i]-l*l);
				M[j]=max(M[j],2*y+1);
			}
		}
		ans=0;
		for(i=1;i<=n;i++){
			for(j=x[i]-r[i];j<=x[i]+r[i];j++){
				if(M[j]>0){
					ans+=M[j];
					M[j]=0;
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
