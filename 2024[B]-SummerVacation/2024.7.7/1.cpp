#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,len;
};
nod a[2000009];
const int inf=1e18+9;
int n,m,q,i,L,R,f[200009],len[200009],cnt,ans[200009];
bool cmp(nod x,nod y){
	return x.len>y.len;
}
int find(int x){
	if(f[x]==x)return x;
	else{
		f[x]=find(f[x]);
		return f[x];
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m>>q;
	for(i=1;i<=n;i++)f[i]=i;//并查集初始化 
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].len);
	}
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){//未连接 
			f[find(a[i].v)]=find(a[i].u);
			len[++cnt]=a[i].len;
		}
	}
	ans[n]=0;
	for(i=1;i<=n;i++){
		ans[i]=inf;
	}
	for(i=n-1;i>=(n-1)-cnt+1;i--){
		ans[i]=len[n-i];
	}
	for(int o=1;o<=q;o++){
		scanf("%lld%lld",&L,&R);
		if(ans[R]==inf){
			printf("NO ANSWER\n");
		}
		else{
			printf("%lld\n",ans[R]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
