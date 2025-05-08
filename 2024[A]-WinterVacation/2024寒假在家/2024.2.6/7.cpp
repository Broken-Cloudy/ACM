#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
int T,n,a[109],f[109],i,j;
int main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);
		
		for(i=1;i<=n;i++)f[i]=INF;f[1]=1;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++){
			int len=a[i];
			if(a[i]==1){
				f[i]=f[max(i-1,1)]+1;
			}
			else{
				if(f[i]==1){
				for(j=i+1;j<=min(n,i+len-1);j++){
					f[j]=f[i]+1;
				}
			}
			if(i-len+1<=1){
				for(j=1;j<=i;j++){
					f[j]=1;
				}
			}
			for(j=i;j>=max(1,i-len+1);j--){
				f[i]=min(f[i],f[j]+1);
			}
			}
			
		}
		printf("%d\n",f[n]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
