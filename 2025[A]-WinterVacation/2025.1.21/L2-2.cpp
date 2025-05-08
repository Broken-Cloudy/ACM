#include<bits/stdc++.h>
#define int long long
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
using namespace std;
struct nod{
	int ch[2];
}tree[39];
int n,i,hou[39],zhong[39],bh[39];
void dfs(int zuol,int zuor,int youl,int your){
	
}
signed main(){
	freopen("L2-2.in","r",stdin);freopen("L2-2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&hou[i]);
	for(i=1;i<=n;i++)scanf("%lld",&zhong[i]),bh[zhong[i]]=i;
	dfs(1,n,1,n);
	fclose(stdin);fclose(stdout);
	return 0;
}
