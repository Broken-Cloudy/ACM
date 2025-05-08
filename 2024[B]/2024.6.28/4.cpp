#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p,a[12][12],c[12][12],b[12][12],i,j,pow2[10009];
int q[10000009],num[10000009],step[10000009],memo[12][12][10009];
bool f=0;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n>>m>>p;
	/*pow2[0]=1%(p-1);pow2[1]=2%(p-1);
	for(i=2;i<=10001;i++){
		pow2[i]=pow2[i-1]*2%(p-1);
	}*/
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%lld",&b[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			c[i][j]=a[i][j]%(p-1);
		}
	}
	int d=1,r=0;
	q[++r]=1*100+1;
	step[r]=0;
	num[r]=c[1][1];
	while(d<=r){
		int x=q[d]/100,y=q[d]%100,S=num[d];
		if(x==n&&y==m&&num[d]==0){
			cout<<step[d]<<endl;
			f=1;
			break;
		}
		if(x-1>0){
			if(memo[x-1][y][(S+c[x-1][y])%(p-1)]==0&&((x-1)!=1||y!=1)){
				memo[x-1][y][(S+c[x-1][y])%(p-1)]==step[d]+1;
				q[++r]=(x-1)*100+(y);
				step[r]=step[d]+1;
				num[r]=(S+c[x-1][y])%(p-1);
			}
		}
		if(x+1<=n){
			if(memo[x+1][y][(S+c[x+1][y])%(p-1)]==0&&((x+1)!=1||y!=1)){
				memo[x+1][y][(S+c[x+1][y])%(p-1)]==step[d]+1;
				q[++r]=(x+1)*100+(y);
				step[r]=step[d]+1;
				num[r]=(S+c[x+1][y])%(p-1);
			}
		}
		if(y+1<=m){
			if(memo[x][y+1][(S+c[x][y+1])%(p-1)]==0&&(x!=1||(y+1)!=1)){
				memo[x][y+1][(S+c[x][y+1])%(p-1)]==step[d]+1;
				q[++r]=(x)*100+(y+1);
				step[r]=step[d]+1;
				num[r]=(S+c[x][y+1])%(p-1);
			}
		}
		if(y-1>0){
			if(memo[x][y-1][(S+c[x][y-1])%(p-1)]==0&&(x!=1||(y-1)!=1)){
				memo[x][y-1][(S+c[x][y-1])%(p-1)]==step[d]+1;
				q[++r]=(x)*100+(y-1);
				step[r]=step[d]+1;
				num[r]=(S+c[x][y-1])%(p-1);
			}
		}
		d++;
	}
	if(f==0){
		cout<<"-1"<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
