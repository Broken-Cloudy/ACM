#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
int a[98],n,i,len,f[98][98],j,k;
char s[98];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++){
		a[i]=s[i]-'A'+1;
	}
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)f[i][j]=INF;
	for(i=1;i<=n;i++)f[i][i]=1;
	for(len=2;len<=n;len++){
		for(i=1;i<=n-len+1;i++){
			j=i+len-1;
			if(a[i]==a[j]){
				f[i][j]=min(f[i][j],f[i+1][j]);
				f[i][j]=min(f[i][j],f[i][j-1]);
			}
			else{
				f[i][j]=min(f[i][j],f[i+1][j]+1);
				f[i][j]=min(f[i][j],f[i][j-1]+1);
			}
			for(k=1;k<n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
			}
		}
	}
	cout<<f[1][n]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
