#include<bits/stdc++.h>
using namespace std;
int i,n,j;
long long a[100010],k,kk,f[100010][18],ans;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		k=a[i];
		for(j=1;j<=18;j++){//计算最大转移 
			if(k&1)kk=max(f[i-1][j]+1,kk);
			k=k>>1;
		}
		k=a[i];
		for(j=1;j<=18;j++){//可转移 
			if(k&1)f[i][j]=max(f[i-1][j]+1,kk);
			else f[i][j]=f[i-1][j];
			k=k>>1;
		}
	}
	for(i=1;i<=18;i++)ans=max(ans,f[n][i]);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
} 
