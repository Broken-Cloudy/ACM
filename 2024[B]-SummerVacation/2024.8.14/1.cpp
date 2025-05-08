#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,i,val[1009][209],w[1009][209],ans,a,b,j,g,V[1009];
int f[1009];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
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
				for(j=b;j<a+b;j++){
					val[i][j]=j;
					w[i][j]=w[i][j-1]+1;
					if(w[i][j]==a*b)val[i][j]++;
				}
				V[i]=a+b-1;//物品数量 
			}
			else{
				for(j=1;j<a;j++){
					val[i][j]=j;
					w[i][j]=b*j;
				}
				for(j=a;j<a+b;j++){
					val[i][j]=j;
					w[i][j]=w[i][j-1]+1;
					if(w[i][j]==a*b)val[i][j]++;
				}
				V[i]=a+b-1;//物品数量 
			}
		}
		for(g=1;g<=n;g++){//小组 
			for(i=k+100;i>=0;i--){
				for(j=1;j<=V[g];j++){
					if(i>=val[g][j]){
						f[i]=min(f[i],f[i-val[g][j]]+w[g][j]);
					}
				}
			}
		}
		for(i=k;i<=k+100;i++){
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
