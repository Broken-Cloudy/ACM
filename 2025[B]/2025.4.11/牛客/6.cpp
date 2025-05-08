#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,y,j,k,c[109],a[109][12],b[109][12],i,f[109][109],C,B,tt,ANS,ttt;
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n>>x>>y;
	for(j=1;j<=n;j++){
		scanf("%lld",&c[j]);
		for(i=1;i<=c[j];i++)scanf("%lld",&a[j][i]);
		for(i=1;i<=c[j];i++)scanf("%lld",&b[j][i]);
	}
	for(C=1;C<=n;C++){//手牌上限 100
		B=n-C;//未使用的桃 
		for(tt=0;tt<=B;tt++){//物品选择数 100
			if(tt>0)for(i=1;i<=n;i++){//100
				for(j=1;j<=c[i];j++){//10
					for(k=C;k>=b[i][j];k--){//100
						if(tt==1||f[k-b[i][j]][tt-1])f[k][tt]=max(f[k][tt],f[k-b[i][j]][tt-1]+a[i][j]);
					}
				}
			}
			for(i=1;i<=B-tt;i++){//100
				ttt=tt+i;
				for(k=C;k>=y;k--){//100
					if(ttt==1||f[k-y][ttt-1])f[k][ttt]=max(f[k][ttt],f[k-y][ttt-1]+x);
				}
			}
		}
	}
	for(i=1;i<=100;i++){
		for(j=1;j<=100;j++){
			ANS=max(ANS,f[i][j]);
		}
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
