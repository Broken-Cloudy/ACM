#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[100009];
int ans[100009],u,v,NUM,FF=1;
int n,m,i,cnt,f[100009],vis[100009],fir1[100009],fir2[100009],q[100009],qcnt;
int r1(int x){return x;}
int r2(int x){
	if(x%2==0){
		return x-1;
	}
	else return x+1;
}
void dfs1(int x){
	vis[x]=1;
	for(int i=fir1[x];i;i=a[i].next){
		if(!vis[a[i].v])dfs1(a[i].v);
	}	
	q[++qcnt]=x;
}
void dfs2(int x,int y){
	vis[x]=0;f[x]=y;
	for(int i=fir2[x];i;i=a[i].next){
		if(vis[a[i].v])dfs2(a[i].v,y);
	}
}
void add(int u,int v,int ff){
	cnt++;
	if(!ff)a[cnt].next=fir1[u];
	else a[cnt].next=fir2[u];
	a[cnt].u=u;a[cnt].v=v;
	if(!ff)fir1[u]=cnt;
	else fir2[u]=cnt;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&u,&v);
		add(r1(u),r2(v),0);add(r2(v),r1(u),1);
		add(r1(v),r2(u),0);add(r2(u),r1(v),1);
	}
	for(i=1;i<=2*n;i++){
		if(!vis[i])dfs1(i);
	}
	for(i=qcnt;i>=1;i--){
		if(vis[q[i]]){
			NUM++;
			dfs2(q[i],NUM);
		}
	}
	for(i=1;i<=2*n;i+=2){
		if(f[r1(i)]==f[r2(i)]){
			FF=0;
			break;
		}
	}
	if(FF==0)cout<<"NIE"<<endl;
	else{
		for(i=1;i<=2*n;i+=2){
			if(f[r1(i)]>f[r2(i)]){
				ans[++ans[0]]=r1(i);
			}
			else ans[++ans[0]]=r2(i);
		}
		sort(ans+1,ans+1+ans[0]);
		for(i=1;i<=ans[0];i++){
			printf("%lld\n",ans[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
