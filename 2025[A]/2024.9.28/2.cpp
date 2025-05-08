#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[400009];
int n,k,i,color[200009],x,y,inters[200009];
int cnt,fir[200009];
void add(int x,int y){
	cnt++;
	a[i].next=fir[x];a[i].u=x;a[i].v=y;
	fir[x]=cnt;
}
void dfs(int u){
	int i;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=k;i++)scanf("%lld",&color[i]);
	for(i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
