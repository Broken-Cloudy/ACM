#include<bits/stdc++.h>
using namespace std;
struct nod{
	int u,v,next;
}a[200009];
int N,i,fa,b[100009],K,KK,FF,gen,cnt,fir[100009],ans[100009];
bool vis[100009];
void dfs(int u){
	int i,t;
	priority_queue<int,vector<int>,greater<int>>q;
	vis[u]=1;
	ans[++ans[0]]=u;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			q.push(v);
		}
	}
	while(!q.empty()){
		t=q.top();q.pop();
		dfs(t);
	}
}
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++){
		scanf("%d",&fa);
		b[fa]++;
		if(fa==0)gen=i;
		else add(fa,i);
	}
	FF=1;
	for(i=1;i<=N;i++)if(b[i]>0)K=b[i];
	for(i=1;i<=N;i++){
		if(K!=b[i]&&b[i]>0){
			FF=0;
			K=max(K,b[i]);
		}
	}
	if(FF==0)printf("%d no\n",K);
	else printf("%d yes\n",K);
	dfs(gen);
	for(i=1;i<=ans[0];i++){
		if(i==ans[0])printf("%d\n",ans[i]);
		else printf("%d ",ans[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
