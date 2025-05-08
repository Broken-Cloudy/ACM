#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,x[100009],y[100009],z[100009],s[100009],W,u,v,w;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		vector<tuple<int,int,int>>d;
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld%lld%lld",&u,&v,&w);
			d.emplace_back(u,v,w);
		}
		for(auto [X,Y,Z]:d){
			x[X]++;y[Y]++;z[Z]++;
		}
		i=0;
		for(auto [X,Y,Z]:d){
			i++;
			W=max(x[X],max(y[Y],z[Z]))-1;
			s[i]=W;
		}
		sort(s+1,s+1+n);s[n+1]=999999999ll;
		for(i=0;i<=n-1;i++){
			int k=lower_bound(s+1,s+1+n,i)-s;
			if(i<n-1)printf("%lld ",n-((n+1)-k));
			else printf("%lld\n",n-((n+1)-k));
		}
		for(auto [X,Y,Z]:d){
			x[X]--;y[Y]--;z[Z]--;
		}		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
