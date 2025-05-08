#include<bits/stdc++.h>
#define int long long
#define inf 1000000009LL
using namespace std;
struct edg{
	int u,v,val;
};
edg a[200009];
int T,i,j,n,f[200009];
bool cmp(edg x,edg y){
	return x.val<y.val;
}
int find(int x){
	if(f[x]==x)return x;
	else{
		f[x]=find(f[x]);
		return f[x];
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)f[i]=i;
		for(i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].val);
		}
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=n;i++){
			int u=find(a[i].u);
			int v=find(a[i].v);
			if(u==v){//×æÏÈÏàÍ¬ 
				
			}
			else{
				f[u]=v;
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
