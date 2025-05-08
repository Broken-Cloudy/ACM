#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int next,u,v;
}a[80009];
bool FF;
int T,n,m,i,cnt,fir1[40009],fir2[40009],q[40009],vis[40009],NUM,qcnt,f[40009];
//汉式h--0 满式m--1 
int tr(int x){return (x+n);}
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
void getin(){
	int i,j,a=0,b=0;
	bool f1,f2;
	string s1,s2;
	cin>>s1>>s2;
	int len1=s1.length();
	int len2=s2.length();
	f1=(s1[0]=='h'?0:1);f2=(s2[0]=='h'?0:1);
	for(i=1;i<len1;i++)a=a*10+(s1[i]-'0');
	for(i=1;i<len2;i++)b=b*10+(s2[i]-'0');
	build(a,f1,b,f2);
}
void clear(){
	memset(a,0,sizeof(a));
	memset(fir1,0,sizeof(fir1));
	memset(fir2,0,sizeof(fir2));memset(f,0,sizeof(f));
	memset(q,0,sizeof(q));memset(vis,0,sizeof(vis));
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);FF=1;
		for(i=1;i<=m;i++)getin();
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
		if(FF==0)printf("BAD\n");
		else printf("GOOD\n");
		clear();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
