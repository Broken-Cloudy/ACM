#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_N=3e5+9;
struct ANS{
	int x,y;
}ans[MAX_N];
int T,x,y,i,anss,n,fir[MAX_N],vis[MAX_N],cnt,du[MAX_N],kk,Q1,Q2;
struct nod{
	int next,u,v;
}a[2*MAX_N];
bool FF;
void A(int x,int y){
	anss++;
	ans[anss].x=x;ans[anss].y=y;
}
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
pair<int,int> dfs(int u,int depth){
	int i,num,Que=-1;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			auto [x,y]=dfs(v,depth+1);
			if(depth==0){
				if(x==1&&Q1==-1){
					Q1=v;
				}
				else if(x==1&&Q1>0){
					A(v,Q1);Q1=-1;
				}
				else if(x==2&&Q2==-1){
					Q2=y;
				}
				else{
					A(u,y);
				}
			}
			else{
				if(x==1&&Que==-1){
					Que=v;
				}
				else if(x==1&&Que>0){
					A(v,Que);Que=-1;
				}
				else{
					A(u,y);
				}
			}
		}
	}
	if(depth>0){
		if(Que!=-1){
			return make_pair(2LL,Que);
		}
		else{
			return make_pair(1LL,-1);
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;FF=0;anss=0;Q1=-1;Q2=-1;
		for(i=1;i<=n;i++)fir[i]=0,du[i]=0,vis[i]=0;
		for(i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
			du[x]++;du[y]++;
		}
		for(i=1;i<=n;i++){
			if(du[i]%2==0)FF=1,kk=i;
		}
		if(FF==0){
			printf("-1\n");
			continue;
		}
		dfs(kk,0);
		if(Q2>0&&Q1>0){
			A(Q1,Q2);
		}
		else if(Q2>0&&Q1==-1){
			A(kk,Q2);
		}
		printf("%lld\n",anss);
		for(i=1;i<=anss;i++){
			printf("%lld %lld\n",ans[i].x,ans[i].y);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
