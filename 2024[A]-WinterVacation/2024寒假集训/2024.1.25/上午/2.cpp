#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[350],i,n,len,j,f[350][350],k,sum[350];
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	memset(f,0x7f,sizeof(f));
	for(i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(i=1;i<=n;i++)f[i][i]=0;
	for(len=2;len<=n;len++){
		for(i=1;i<=n-len+1;i++){
			j=i+len-1;
			for(k=i;k<j;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	cout<<f[1][n]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
