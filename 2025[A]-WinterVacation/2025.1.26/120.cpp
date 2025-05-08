#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int fa,mo;
	char ff;
}a[100009];
int N,Q,i,j,k,c,fa,mo,x,y,b[2][109];
void dfs(int u,int depth,int type){
	if(depth>5)return;
	else{
		b[type][++b[type][0]]=u;
		if(a[u].fa!=-1)dfs(a[u].fa,depth+1,type);
		if(a[u].mo!=-1)dfs(a[u].mo,depth+1,type);
	}
}
signed main(){
	freopen("120.in","r",stdin);freopen("120.out","w",stdout);
	cin>>N;
	for(i=0;i<=99999LL;i++)a[i].fa=-1,a[i].mo=-1;
	for(i=1;i<=N;i++){
		scanf("%lld %c %lld %lld",&k,&c,&fa,&mo);
		a[k].fa=fa;a[k].mo=mo;a[k].ff=c;
		if(fa>=0)a[fa].ff='M';
		if(mo>=0)a[mo].ff='F';
	}
	cin>>Q;
	while(Q--){
		scanf("%lld%lld",&x,&y);
		if(a[x].ff==a[y].ff){
			printf("Never Mind\n");
			continue;
		}
		else{
			bool FF=1;
			b[0][0]=0;b[1][0]=0;
			dfs(x,1,0);
			dfs(y,1,1);
			for(i=1;i<=b[0][0];i++){
				for(j=1;j<=b[1][0];j++){
					if(b[0][i]==b[1][j]){
						FF=0;
						break;
					}
				}
				if(FF==0)break;
			}
			if(FF==0)printf("No\n");
			else printf("Yes\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
