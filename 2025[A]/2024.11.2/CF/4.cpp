#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,m,a[1009][1009],ans,b[8009];
char c;
int work(int i,int j,int x,int y){
	int k,ans=0;
	if(x<i||y<j)return 0LL;
	else{
		b[0]=0;
		for(k=j;k<=y;k++){
			b[++b[0]]=a[i][k];
		}
		for(k=i+1;k<=x;k++){
			b[++b[0]]=a[k][y];
		}
		if(i!=x&&j!=y)for(k=y-1;k>=i;k--){
			b[++b[0]]=a[x][k];
		}
		if(i!=x&&j!=y)for(k=x-1;k>j;k--){
			b[++b[0]]=a[k][j];
		}
		if(i!=x&&j!=y){
			b[++b[0]]=b[1];b[++b[0]]=b[2];b[++b[0]]=b[3];
		}
		for(k=1;k<=b[0]-3;k++){
			if(b[k]==1&&b[k+1]==5&&b[k+2]==4&&b[k+3]==3){
				ans++;
			}
		}
		return ans;
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);ans=0;
		for(i=1;i<=n;i++){
			getchar();
			for(j=1;j<=m;j++){
				c=getchar();
				a[i][j]=c-'0';
			}
		}
		for(i=1;i<=n;i++){
			ans+=work(i,i,n-i+1,m-i+1);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
