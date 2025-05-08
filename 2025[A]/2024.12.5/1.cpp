#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=998244353998244353LL;
int T,i,j,k,len1,len2,len3,f[1009][1009];
char a[2009],b[2009],c[2009];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%s",a+1);scanf("%s",b+1);scanf("%s",c+1);
		len1=strlen(a+1);len2=strlen(b+1);len3=strlen(c+1);
		for(i=0;i<=len1;i++)for(j=0;j<=len2;j++)f[i][j]=inf;f[0][0]=0;
		for(k=1;k<=len3;k++){
			for(i=0;i<=min(k,len1);i++){
				j=k-i;
				if(i==0){
					if(b[j]==c[k])f[i][j]=min(f[i][j-1],f[i][j]);
					else f[i][j]=min(f[i][j-1]+1,f[i][j]);
				}
				else if(j==0){
					if(a[i]==c[k])f[i][j]=min(f[i-1][j],f[i][j]);
					else f[i][j]=min(f[i-1][j]+1,f[i][j]);
				}
				else{
					if(b[j]==c[k])f[i][j]=min(f[i][j-1],f[i][j]);
					else f[i][j]=min(f[i][j-1]+1,f[i][j]);
					if(a[i]==c[k])f[i][j]=min(f[i-1][j],f[i][j]);
					else f[i][j]=min(f[i-1][j]+1,f[i][j]);									
				}
			}
		}
		printf("%lld\n",f[len1][len2]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
