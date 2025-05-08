#include<bits/stdc++.h>
using namespace std;
const long long inf=1e9+7;
long long n,i,a[100009],b[6],f[100009][5],g[2009][2009],sum=1,ans,j;
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	g[0][0]=g[1][0]=g[0][1]=g[1][1]=1;
	for(i=2;i<=2000;i++){
		g[i][0]=1;
		for(j=1;j<=i;j++){
			g[i][j]=(g[i-1][j-1]+g[i-1][j])%inf;
		}
	}
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	for(i=0;i<=b[1];i++){
		f[i][1]=g[b[1]][i];
	}
	f[0][2]=1;
	for(i=1;i<=b[2];i++){
		f[i][2]=f[i-1][2]+1;
	}
	for(i=1;i<=b[2];i++){
		f[i][2]*=g[b[2]][i];
			f[i][2]%=inf;
			sum+=f[i][2];
			sum%=inf;
			f[0][3]=1;
	}
	
	for(i=1;i<=b[3];i++){
		f[i][3]=f[i-1][3]+1;
	}
	for(i=1;i<=b[3];i++){
		f[i][3]*=g[b[3]][i];
		f[i][3]%=inf;
	}
	for(i=0;i<=b[3];i++){
		f[i][3]*=sum;
		f[i][3]%=inf;
	}
	for(i=0;i<=b[3];i++){
		f[i][3]*=b[1];
		f[i][3]%=inf;
	}
	for(i=0;i<=b[3];i++){
		ans+=f[i][3];
		ans%=inf;
	}
	ans--;
	cout<<(ans+inf)%inf<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
