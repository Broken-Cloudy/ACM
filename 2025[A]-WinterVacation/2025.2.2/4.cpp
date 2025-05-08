#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int len,bh;
}t;
queue<nod>q1,q2;
int T,n,s1,s2,a[1009][1009],b[1009][1009],m1,m2,x,y,i,j;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		while(!q1.empty())q1.pop();while(!q2.empty())q2.pop();
		scanf("%lld%lld%lld",&n,&s1,&s2);
		t.len=0;t.bh=s1;q1.push(t);t.len=0;t.bh=s2;q2.push(t);
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)a[i][j]=b[i][j]=0;
		scanf("%lld",&m1);
		for(i=1;i<=m1;i++){
			scanf("%lld%lld",&x,&y);
			a[x][y]=a[y][x]=1;
		}
		scanf("%lld",&m2);
		for(i=1;i<=m2;i++){
			scanf("%lld%lld",&x,&y);
			b[x][y]=b[y][x]=1;
		}
		for(i=1;i<=500;i++){
			while(!q1.empty()){
				
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
