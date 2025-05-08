#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[8000009];
int n,m,i,j,u,ui,v,vi,f[2000009],NUM;
int fir1[2000009],fir2[2000009],vis[2000009],cnt,qcnt,q[4000009];
bool FF=1;
int tr(int x){return x+1000000LL;}
void dfs1(int x){
	vis[x]=1;
	for(int i=fir1[x];i;i=a[i].next){
		if(!vis[a[i].v])dfs1(a[i].v);
	}
	q[++qcnt]=x;
}
void dfs2(int x,int y){
	vis[x]=0;f[x]=y;//标明强连通从属关系 
	for(int i=fir2[x];i;i=a[i].next){
		if(vis[a[i].v])dfs2(a[i].v,y);
	}
}
void add(int u,int v,bool ff){
	cnt++;
	if(!ff)a[cnt].next=fir1[u];//正图 
	else a[cnt].next=fir2[u];//反图 
	a[cnt].u=u;a[cnt].v=v;
	if(!ff)fir1[u]=cnt;//正图 
	else fir2[u]=cnt;//反图 
}
void build(int u,int ui,int v,int vi){
	if(u==v){//1-SAT 
		if(ui!=vi)return;
		else if(ui==1){
			add(tr(u),u,0);add(u,tr(u),1);//u'-->u
		}
		else{
			add(u,tr(u),0);add(tr(u),u,1);//u-->u'
		}
		return;
	}
	if(ui==1&&vi==1){
		add(tr(u),v,0);add(v,tr(u),1);//u'-->v
		add(tr(v),u,0);add(u,tr(v),1);//v'-->u
	}
	else if(ui==1&&vi==0){
		add(tr(u),tr(v),0);add(tr(v),tr(u),1);//u'-->v'
		add(v,u,0);add(u,v,1);//v-->u
	}
	else if(ui==0&&vi==1){
		add(u,v,0);add(v,u,1);//u-->v
		add(tr(v),tr(u),0);add(tr(u),tr(v),1);//v'-->u'
	}
	else{
		add(u,tr(v),0);add(tr(v),u,1);//u-->v'
		add(v,tr(u),0);add(tr(u),v,1);//v-->u'
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld%lld",&u,&ui,&v,&vi);
		build(u,ui,v,vi);
	}
	for(i=1;i<=2*n;i++)if(!vis[i])dfs1(i);
	for(i=qcnt;i>=1;i--){
		if(vis[q[i]]){
			NUM++;
			dfs2(q[i],NUM);
		}
	}
	for(i=1;i<=n;i++){
		if(f[i]==f[tr(i)]){
			FF=0;
			break;
		}
	}
	if(FF==0)cout<<"IMPOSSIBLE"<<endl;
	else{
		cout<<"POSSIBLE"<<endl;
		for(i=1;i<=n;i++){
			if(i==n)printf("%lld\n",(f[i]>f[tr(i)]));
			else printf("%lld ",(f[i]>f[tr(i)]));
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
