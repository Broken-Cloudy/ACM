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
		return x.dis>y.dis;//大根堆 
	}
};
edg edge[400009];
nod a[400009];
int fir[400009],n,i,u,v,length,cnt,b[400009],z;
bool vis[400009];//dijkstra
void add(int u,int v,int length){
	edge[++cnt].next=fir[u];
	fir[u]=cnt;
	edge[cnt].start=u;
	edge[cnt].end=v;
	edge[cnt].len=length;
}
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>z;
	priority_queue<nod,vector<nod>,cmp>q;
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);b[i]%=n;
		if((b[i]+i)%n!=i)add(i,(b[i]+i)%n,1);
		add(i,(i+1)%n,1);//注意求余数 
	}
	for(i=0;i<n;i++){
		a[i].bh=i;
		a[i].dis=inf;
	}
	//a[0]=0 vis[0]=1;这个不能有 
	if(b[0]==0){
		a[1].dis=2;
		q.push(a[1]);
	}
	else{
		a[b[0]].dis=1;
		q.push(a[b[0]]);
	}
	while(!q.empty()){
		nod node=q.top();q.pop();//这是个点 
		int x=node.bh;//x是个点 
		if(vis[x]==1)continue;
		else{
			vis[x]=1;
		}
		for(i=fir[x];i;i=edge[i].next){//fir[x]是条边 
			int y=edge[i].end;//y是个点 
			if(a[x].dis+edge[i].len<a[y].dis){
				nod addition;
				addition.bh=y;addition.dis=a[x].dis+edge[i].len;
				a[y]=addition;
				q.push(addition);
			}
		}
	}
	printf("%d\n",a[z].dis);
	fclose(stdin);fclose(stdout);
	return 0;
} 
