#include<bits/stdc++.h>
using namespace std;
int n,i,v,cnt,fir[100009],geng,tree[100009],maxx=-1;
bool vis[100009],flag=0;
struct nod{
	int next,v;
};
nod a[400009];
int d[400009],h,r;
void add(int u,int v){
	cnt++;
	a[cnt].next=fir[u];
	a[cnt].v=v;
	fir[u]=cnt;
}
void dfs(int x){
	if(vis[x]==1)return;
	priority_queue<int,vector<int>,greater<int> >q;
	d[++r]=x;vis[x]=1;
	for(i=fir[x];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			q.push(v);
		}
	}
	while(!q.empty()){
		dfs(q.top());
		q.pop();
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&v);
		if(v==0){
			geng=i;
		}
		else{
			add(i,v);
			add(v,i);
		}
	}
	h=1;r=0;d[++r]=geng;
	while(h<=r){
		int u=d[h];
		if(vis[u]==1)continue;
		vis[u]=1;
		int num=0;
		for(i=fir[u];i;i=a[i].next){
			int v=a[i].v;
			if(vis[v]==0){
				d[++r]=v;
				num++;
			}
		}
		tree[u]=num;
		h++;
	}
	for(i=1;i<=n;i++)maxx=max(tree[i],maxx);
	for(i=1;i<=n;i++)if(tree[i]!=0&&maxx!=tree[i])flag=1;
	cout<<maxx<<' ';
	if(flag==1)cout<<"no"<<endl;
	else cout<<"yes"<<endl;
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d));
	r=0;
	dfs(geng);
	for(i=1;i<=n;i++){
		if(i!=n)printf("%d ",d[i]);
		else printf("%d\n",d[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
