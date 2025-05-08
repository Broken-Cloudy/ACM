#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,i,val[1009][109],w[1009][109],ans,a,b,j,g,V[1009];
int f[1009];
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=k+10;i++)f[i]=10000000000009ll;
		ans=10000000000009ll;
		for(i=1;i<=n;i++){
			scanf("%lld%lld",&a,&b);
			if(a<=b){
				for(j=1;j<b;j++){
					val[i][j]=j;
					w[i][j]=a*j;
				}
				val[i][b]=a+b;
				w[i][j]=a*b;
				V[i]=b;//物品数量 
			}
			else{
				for(j=1;j<a;j++){
					val[i][j]=j;
					w[i][j]=b*j;
				}
				val[i][a]=a+b;
				w[i][j]=a*b;
				V[i]=a;//物品数量 
			}
		}
		for(g=1;g<=n;g++){//小组 
			for(i=k+10;i>=0;i--){
				for(j=1;j<=V[g];j++){
					if(i>=val[g][j]){
						f[i]=min(f[i],f[i-val[g][j]]+w[g][j]);
					}
				}
			}
		}
		for(i=k;i<=k+10;i++){
			ans=min(ans,f[k]);
		}
		if(ans==10000000000009ll){
			printf("-1\n");
		}
		else printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
