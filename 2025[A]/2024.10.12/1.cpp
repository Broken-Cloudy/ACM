#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,i,j,k,ans,ztkx[109][109],zt[109],num[109],shu[109],f[109][109][109];//状态很少 
char c[109][19];
void Pre(){
	int i,j,k,kk;
	bool ff;
	for(i=0;i<(1<<m);i++){//有效状态 
		if((i&(i<<1))==0&&(i&(i<<2))==0){
			zt[++zt[0]]=i;kk=0;
			for(j=0;(1<<j)<=i;j++){
				if(i&(1<<j))kk++;
			}
			num[zt[0]]=kk;
			for(k=1;k<=n;k++){
				ff=0;
				for(j=0;(1<<j)<=i;j++){
					if((i&(1<<j))&&(shu[k]&(1<<j))==0){
						ff=1;break;
					}
				}
				if(ff==1)ztkx[zt[0]][k]=0;
				else ztkx[zt[0]][k]=1;
			}
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=m;j++){
			c[i][j]=getchar();
			shu[i]=(shu[i]<<1)+(c[i][j]=='P'?1:0);
		}
	}
	Pre();
	if(n==1){
		for(i=1;i<=zt[0];i++)if(ztkx[i][1])ans=max(ans,num[i]);
		printf("%lld\n",ans);
	}
	else{
		for(i=1;i<=zt[0];i++){//i行
			for(j=1;j<=zt[0];j++){//i-1行 
				if((zt[i]&zt[j])==0&&ztkx[j][1]&&ztkx[i][2]){
					f[2][j][i]=max(f[2][j][i],num[i]+num[j]);
					ans=max(ans,f[2][j][i]);
				}
			}
		}
		for(t=3;t<=n;t++){ 
			for(i=1;i<=zt[0];i++){//i行
				for(j=1;j<=zt[0];j++){//i-1行 
					for(k=1;k<=zt[0];k++){//i-2行 
						if((zt[i]&zt[j])==0&&(zt[i]&zt[k])==0&&(zt[k]&zt[j])==0){
							if(ztkx[i][t]&&ztkx[j][t-1]&&ztkx[k][t-2]){
								f[t][j][i]=max(f[t][j][i],f[t-1][k][j]+num[i]);
								ans=max(ans,f[t][j][i]);
							}
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
