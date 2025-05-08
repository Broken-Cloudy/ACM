#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
};
nod a[400009];
int T,fir[200009],cnt,n,m,i,j,x,y;
void add(int x,int y){
	cnt++;
	a[i].next=fir[x];a[i].u=x;a[i].v=y;
	fir[x]=cnt;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=m;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(x,y);
		}
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
