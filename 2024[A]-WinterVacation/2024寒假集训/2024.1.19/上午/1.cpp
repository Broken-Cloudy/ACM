#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long double c1[51],c2[51],val[51];
__int128 F[51];
int n,m,i,j,k;
int main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	F[1]=1;
	for(i=2;i<=33;i++){//阶乘 
		F[i]=F[i-1]*i;
	}
	while(~scanf("%d%d",&n,&m)){
		for(i=0;i<n;i++){
			scanf("%d",&val[i]);
		}
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(i=0;i<=val[0];i++){
			c1[i]=1.0/F[i];//初始化为阶乘分之一,连续挑几次a1,都只有一种方案 
		}
		for(i=1;i<n;i++){//轮数 
			for(j=0;j<=m;j++){
				for(k=0;k+j<=m&&k<=val[i];k++){
					c2[j+k]+=c1[j]/F[k];
				}
			}
			for(j=0;j<=m;j++){
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		printf("%.0lf\n",c1[m]*F[m]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
