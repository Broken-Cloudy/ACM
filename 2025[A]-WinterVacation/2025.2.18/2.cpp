#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int x,y;
}t;
int T,i,n,m,j,a[709][709],k,x,y,dx[6],dy[6],kk,ANS;
int ans[500009];
bool check(int x,int y){
	if(x>=1&&x<=n&&y>=1&&y<=m){
		return 1;
	}
	else return 0;
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	dx[1]=1;dx[2]=-1;dx[3]=0;dx[4]=0;
	dy[1]=0;dy[2]=0;dy[3]=-1;dy[4]=1;
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%lld",&a[i][j]);
		for(i=1;i<=n*m;i++)ans[i]=0;
		for(i=1;i<=n;i++)for(j=1;j<=m;j++){
			ans[a[i][j]]=max(ans[a[i][j]],1LL);
			for(k=1;k<=4;k++){
				x=i+dx[k];y=j+dy[k];
				if(check(x,y)&&a[x][y]==a[i][j]){
					ans[a[i][j]]=2;
					break;
				}
			}
		}
		sort(ans+1,ans+1+(n*m),cmp);
		i=2;ANS=0;
		while(ans[i]>0&&i<=(n*m)){
			ANS+=ans[i];
			i++;
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
}
