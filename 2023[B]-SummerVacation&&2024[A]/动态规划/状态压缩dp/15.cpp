#include<iostream>
#include<cstdio>
using namespace std;
const long long inf=100000000;
long long f[15][5000],dp[15][5000],ans;//f[i][j];i��ʾ������j��ʾ״̬ 
int zip[15];//ѹ���������״̬ 
int a,n,m,i,j,k;
int main(){
	freopen("15.in","r",stdin);freopen("15.out","w",stdout);
	cin>>m>>n;
	for(i=1;i<=m;i++){//¼��״̬ 
		for(j=1;j<=n;j++){
			scanf("%d",&a);
			if(a)zip[i]+=1<<(n-j);
		}
	}
	for(i=1;i<=m;i++){//Ԥ��������״̬ 
		for(j=0;j<(1<<n);j++){//ö��״̬ 
			if(~zip[i]&j)continue;//״̬��ͻ
			if(j&(j<<1))continue;//���ҳ�ͻ ****
			f[i][++f[i][0]]=j;
		} 
	}
	for(i=1;i<=f[1][0];i++){
		dp[1][i]=1;
	}
	for(i=2;i<=m;i++){//ö������ 
		for(j=1;j<=f[i][0];j++){//������������г�ͻ����� 
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
