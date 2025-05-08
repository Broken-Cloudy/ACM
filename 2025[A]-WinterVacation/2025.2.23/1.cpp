#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u1,u2;
};
int T,n,s1,s2,i,j,m1,m2,x,y;
int a[1009][1009],b[1009][1009];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&s1,&s2);
		for(i=1;i<=n;i++)a[i][0]=b[i][0]=0;
		scanf("%lld",&m1);
		for(i=1;i<=m1;i++){
			scanf("%lld%lld",&x,&y);
			a[x][++a[x][0]]=y;a[y][++a[y][0]]=x;
		}
		scanf("%lld",&m2);
		for(i=1;i<=m2;i++){
			scanf("%lld%lld",&x,&y);
			b[x][++b[x][0]]=y;b[y][++b[y][0]]=x;
		}
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
