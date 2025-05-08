#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[20009];
int N,M,K,i,j,x,y,fir[10009],cnt,Q,b[10009],vis[10009];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>N>>M;
	for(i=1;i<=M;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	cin>>Q;
	while(Q--){
		cin>>K;
		memset(vis,0,sizeof(vis));
		for(i=1;i<=K;i++){
			scanf("%lld",&b[i]);
		}
		for(i=1;i<=K;i++){
			vis[b[i]]=1;
		}
		bool FF=1;
		for(i=1;i<=N;i++){
			if(vis[i]==0){
				for(j=fir[i];j;j=a[j].next){
					if(vis[a[j].v]==0){
						FF=0;
						break;
					}
				}
			}
			if(FF==0)break;
		}
		if(FF==1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
