#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n,p,a[1009][1009],b[1009][1009],c[1009][1009],i,j,f[1009],cc,ff;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m>>p;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%lld",&a[i][j]);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(a[i][j]==1)f[i]++;
	for(i=1;i<=n;i++)for(j=1;j<=p;j++)scanf("%lld",&c[i][j]);
	for(j=1;j<=p;j++){//核心是b的列枚举 这也是c的列 
		if(f[1]%2==0&&c[1][j]==1)cc=1;//构造0001序列 
		else if(f[1]%2==0&&c[1][j]==1)cc=0;//构造0000序列 
		else if(f[1]%2==1&&c[1][j]==0)cc=1;
		else cc=0;
		for(i=2;i<=n;i++){
			if(cc==1){
				if(f[i]%2==0&&c[i][j]==0)ff=-1;
				if(f[i]%2==1&&c[i][j]==1)ff=-1;
			}
			else{
				if(f[i]%2==1&&c[i][j]==0)ff=-1;
				if(f[i]%2==0&&c[i][j]==1)ff=-1;
			}
		}
		if(cc==1){
			b[1][j]=1;
			for(i=2;i<=m;i++)b[i][j]=0;
		}
		else{
			for(i=1;i<=m;i++)b[i][j]=0;
		}
	}
	if(ff==-1)printf("No\n");
	else{
		printf("Yes\n");
		for(i=1;i<=m;i++){
			for(j=1;j<=p;j++){
				if(j==p)printf("%lld\n",b[i][j]);
				else printf("%lld ",b[i][j]);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
