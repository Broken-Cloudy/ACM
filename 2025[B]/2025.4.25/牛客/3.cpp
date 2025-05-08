#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a[200009],i,n,now,f[800009],j,FF,g[200009];
map<int,int>M;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);M.clear();FF=1;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+1+n);f[0]=1;j=1;
		for(i=1;i<=4*n;i++){
			if(f[i]==0&&i<=a[j]&&j<=n){
				f[i]=1;
				if(a[j]<=4*n){
					if(f[a[j]-1]==0){
						f[i]=1;
						f[a[j]-1]=1;
						g[j]=1;
					}
					else if(f[a[j]+1]==0){
						f[i]=1;
						f[a[j]+1]=1;
						g[j]=1;
					}
					j++;
				}
				else{
					break;
				}
			}
		}
		for(i=j;i<=n;i++){
			if(a[i]>4*n){
				if(M[a[i]-1]==0){
					M[a[i]-1]=1;
					g[i]=1;
				}
				else if(M[a[i]+1]==0){
					M[a[i]+1]=1;
					g[i]=1;
				}
				else g[i]=0;
			}
		}
		for(i=1;i<=n;i++)if(g[i]==0)FF=0;
		for(i=1;i<=4*n;i++)f[i]=0,g[(i/4)]=0;
		if(FF==1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
