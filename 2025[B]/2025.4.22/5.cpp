#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,y,i,c[109],j,r,k,a[109][12],b[109][12],rest,cur,group,f[109][109],ANS;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>x>>y;
	for(i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		for(j=1;j<=c[i];j++)scanf("%lld",&a[i][j]);
		for(j=1;j<=c[i];j++)scanf("%lld",&b[i][j]);
		c[i]++;
		a[i][c[i]]=x;b[i][c[i]]=y;
	}
	for(r=0;r<=n;r++){//当前手牌上限,说明打出了几张桃 
		for(group=1;group<=n;group++){//100
			for(j=r;j>=0;j--){//100
				for(k=n-r;k>=1;k--){//4500 最多保留n-r张手牌
					for(i=1;i<=c[group];i++){//选择一个牌占权值1 11
						if(j>=b[group][i]&&k>=1){
							f[j][k]=max(f[j][k],f[j-b[group][i]][k-1]+a[group][i]);
						}
					}
				}
			}
		}
		for(j=r;j>=0;j--)for(k=n-r;k>=0;k--)ANS=max(ANS,f[j][k]);
		memset(f,0,sizeof(f));
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
