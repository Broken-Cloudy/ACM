#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,x,y,du[200009],ANS,ans,fir[200009],cnt,f[200009];
struct nod{
	int next,u,v;
}a[400009];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;ans=0;
		for(i=1;i<=n;i++)fir[i]=0,du[i]=0,f[i]=0;
		for(i=1;i<=n-1;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
			du[x]++;du[y]++;
		}
		//vis[i]=0树干 
		for(i=1;i<=n;i++){
			if(du[i]==1){
				ans++;
			}
		}
		ANS=ans*(n-ans);ans=0;
		for(int u=1;u<=n;u++)if(du[u]>1){//不是叶子 
			for(j=fir[u];j;j=a[j].next){
				int v=a[j].v;
				if(du[v]>1)f[u]++;
			}
			if(du[u]==f[u])ans++;
		}
		for(i=1;i<=n;i++){
			if(du[i]!=f[i]&&du[i]>1){
				ANS+=ans*(f[i]-1);
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
