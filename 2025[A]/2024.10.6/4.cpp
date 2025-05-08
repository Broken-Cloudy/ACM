#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
const int inf=1e9+7;
struct edg{
	int next,start,end,len;
};
struct nod{
	int bh,dis;
};
struct cmp{
	bool operator()(nod x,nod y){
		return x.dis>y.dis;//????? 
	}
};
edg edge[200009];
nod a[200009];
int fir[200009],n,m,s,i,u,v,length,cnt;
bool vis[200009];//dijkstra
void add(int u,int v,int length){
	edge[++cnt].next=fir[u];
	fir[u]=cnt;
	edge[cnt].start=u;
	edge[cnt].end=v;
	edge[cnt].len=length;
}
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n>>m>>s;
	priority_queue<nod,vector<nod>,cmp>q;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&length);
		add(u,v,length);
	}
	for(i=1;i<=n;i++){
		a[i].bh=i;
		a[i].dis=inf;
	}
	a[s].dis=0;
	q.push(a[s]);
	while(!q.empty()){
		nod node=q.top();q.pop();//??????? 
		int x=node.bh;//x????? 
		if(vis[x]==1)continue;
		else{
			vis[x]=1;
		}
		for(i=fir[x];i;i=edge[i].next){//fir[x]?????? 
			int y=edge[i].end;//y????? 
			if(a[x].dis+edge[i].len<a[y].dis){
				nod addition;
				addition.bh=y;addition.dis=a[x].dis+edge[i].len;
				a[y]=addition;
				q.push(addition);
			}
		}
	}
	for(i=1;i<=n;i++){
		printf("%d ",a[i].dis);
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 

