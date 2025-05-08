#include<iostream>
#include<cstdio>
using namespace std;
const long long inf=100000000;
long long f[15][5000],dp[15][5000],ans;//f[i][j];i表示行数，j表示状态 
int zip[15];//压缩后的土地状态 
int a,n,m,i,j,k;
int main(){
	freopen("15.in","r",stdin);freopen("15.out","w",stdout);
	cin>>m>>n;
	for(i=1;i<=m;i++){//录入状态 
		for(j=1;j<=n;j++){
			scanf("%d",&a);
			if(a)zip[i]+=1<<(n-j);
		}
	}
	for(i=1;i<=m;i++){//预处理正常状态 
		for(j=0;j<(1<<n);j++){//枚举状态 
			if(~zip[i]&j)continue;//状态冲突
			if(j&(j<<1))continue;//自我冲突 ****
			f[i][++f[i][0]]=j;
		} 
	}
	for(i=1;i<=f[1][0];i++){
		dp[1][i]=1;
	}
	for(i=2;i<=m;i++){//枚举行数 
		for(j=1;j<=f[i][0];j++){//处理对于上下行冲突的情况 
			for(k=1;k<=f[i-1][0];k++){
				if((f[i][j]&f[i-1][k])==0){
					dp[i][j]+=dp[i-1][k];
					dp[i][j]%=inf;
				}
			}
		}
	}
	for(i=1;i<=f[m][0];i++){
		ans+=dp[m][i];
		ans%=inf;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
} 
