#include<bits/stdc++.h>
using namespace std;
int n,c,d[59],w[59],i,f[59][59],j,a[59][59],b[59],len;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>c;
	memset(f,0x7f,sizeof(f));
	for(i=1;i<=n;i++){
		scanf("%d%d",&d[i],&w[i]);
		b[i]=b[i-1]+w[i];
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			a[i][j]=b[n]-(b[j]-b[i-1]);
		}
	}
	f[c][c]=0;
	for(len=2;len<=n;len++){
		for(i=1;i<=n-len+1;i++){
			j=i+len-1;
			if(i<=c&&c<=j){
				if(i+1<=c)f[i][j]=min(f[i][j],f[i+1][j]+(d[i+1]-d[i])*a[i+1][j]);
				if(j-1>=c)f[i][j]=min(f[i][j],f[i][j-1]+(d[j]-d[j-1])*a[i][j-1]);
			}
		}
	}
	cout<<f[1][n]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
