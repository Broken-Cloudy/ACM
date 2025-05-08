#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9+7;
int T,k,i,j,n,ans,r[5009],Alice,level1,level2;
int cnt,a[5009],f[5009][5009];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		ans=0;cnt=0;
		memset(r,0,sizeof(r));
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)f[i][j]=inf;
		for(i=1;i<=n;i++){
			scanf("%lld",&k);
			r[k]++;
		}
		for(i=1;i<=n;i++){
			if(r[i]>0){
				a[++cnt]=r[i];
				a[cnt]++;
			}
		}
		for(i=2;i<=cnt;i+=2){
			if(a[i+1]>0)level1=min(a[i],a[i+1]);
			else level1=a[i];
			if(a[i+1]>0)level2=a[i]+a[i+1];
			f[i/2][0]=0;
			bool ff=0;
			for(j=1;j<=i/2;j++){//已经选择的个数 
				ff=0;
				if(j!=(i/2))f[i/2][j]=f[i/2-1][j];//选0 
				f[i/2][j]=min(f[i/2][j],f[i/2-1][j-1]+level1);//选1 
				if(a[i+1]>0&&j>=2){
					if(f[i/2-1][j-2]+level2<=f[i/2][j]){//选2 
						f[i/2][j]=f[i/2-1][j-2]+level2;
						ff=1;
					}
				}	
				//答案
				if(a[i+1]>0&&j>=2){//存在2 
					if(a[i]>=a[i+1]){//选后1个
						if(i+1>=f[i/2][j])ans=max(ans,j);
					}
					else if(a[i]<a[i+1]&&ff==0){//没选2，且选择前一个
						if(i>=f[i/2][j])ans=max(ans,j);
					}
					else if(a[i]<a[i+1]&&ff==1){//选2
						if(i+1>=f[i/2][j])ans=max(ans,j);
					}
				}
				else if(i>=f[i/2][j])ans=max(ans,j);
			}
		}
		printf("%lld\n",cnt-ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
