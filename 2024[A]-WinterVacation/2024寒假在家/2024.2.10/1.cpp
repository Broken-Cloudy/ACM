#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
int n,T,i,a[109],j,f[109],k;
int vis[109],iamvis[109],mini[109];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);
		for(i=1;i<=n;i++)vis[i]=0;
		for(i=1;i<=n;i++)iamvis[i]=0;
		for(i=1;i<=n;i++)f[i]=INF;
		for(i=1;i<=n;i++)mini[i]=INF;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++){//对应编号 
			//基础为f[i-1] 
			for(k=1;k<=i;k++){//编号重演 
				if(vis[k-1]==k){
					if(iamvis[k-1]==k){
						continue;
					}
					else{
						for(j=k;j<=min(k+a[k]-1,n);j++){//向后递进 
							f[j]=min(f[j],mini[k]+1);
						}
					}
				}
				else{
					for(j=k;j<=min(k+a[k]-1,n);j++){//向后递进 
						f[j]=min(f[j],f[k-1]+1);
					}
				}
				
			}
			for(j=max(0,i-a[i]);j<=i;j++){//向前递进 
				f[i]=min(f[j]+1,f[i]);
				if(j>=1){
					if(f[j]>=f[i]){
						f[j]=f[i];
						vis[j]=i;
						iamvis[j]=i;
					}
					else{
						iamvis[j]=i;
						mini[j]=min(mini[j],f[i]);
					}
				}
			}
		}
		printf("%d\n",f[n]);
	} 
	fclose(stdin);fclose(stdout);
	return 0;
}
