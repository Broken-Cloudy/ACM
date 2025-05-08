#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[400009];
int T,i,n,x,y;
int fir[200009],cnt,du[200009],ans,K,j;
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;ans=0;K=0;
		for(i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
			du[x]++;du[y]++;
		}
		for(i=1;i<=n;i++){
			if(du[i]>1){
				K++;
			}
		}
		for(i=1;i<=n;i++){
			if(du[i]==1){
				ans+=K;
				for(j=fir[i];j;j=a[j].next){
					
				}
			}
		}
		for(i=1;i<=n;i++)du[i]=0;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
