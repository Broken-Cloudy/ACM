#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,i,j,u,v,w,x,y,vis[100009],vc[100009],du[100009],X,Y,VIS[100009];
map<int,map<int,int> >M;
struct nod{
	int u,v,last,next;
}a[3200009];
int fir[100009],las[100009],cnt,ops,kong[100009];
struct node{
	int x,y,z;
}op[3200009];
void add(int x,int y){
	cnt++;
	M[x][y]=cnt;
	if(fir[x]==0){
		fir[x]=cnt;
		a[cnt].next=0;
		a[cnt].u=x;a[cnt].v=y;
		las[x]=cnt;
	}
	else{
		a[cnt].next=0;
		a[las[x]].next=cnt;
		a[cnt].last=las[x];
		a[cnt].u=x;a[cnt].v=y;
		las[x]=cnt;
	}
}
void del(int x,int y){
	int cnt=M[x][y];
	M[x][y]=0;
	if(fir[x]!=cnt&&las[x]!=cnt){
		a[a[cnt].last].next=a[cnt].next;
		a[a[cnt].next].last=a[cnt].last;
	}
	else{
		if(las[x]==cnt){
			las[x]=a[cnt].last;
			a[las[x]].next=0;
		}
		if(fir[x]==cnt){
			fir[x]=a[cnt].next;
			a[fir[x]].last=0;
		}
	}
	a[cnt].last=-1;a[cnt].next=-1;
}
int dfs(int u){
	int i;
	VIS[u]=1;
	if(du[u]==0)return u;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(M[u][v]){
			VIS[v]=1;
			if(X==0&&Y==0){
				X=u;Y=v;
			}
			break;
		}
	}
	return u;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);M.clear();kong[0]=0;X=Y=0;
		for(i=1;i<=n;i++)fir[i]=0,las[i]=0,du[i]=0,VIS[i]=0;cnt=0;ops=0;
		for(i=1;i<=m;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);du[x]++;du[y]++;
		}
		for(u=1;u<=n;u++){
			if(du[u]==0)continue;
			int fff=0;
			for(i=fir[u];i;i=a[i].next){
				v=a[i].v;
				if(M[u][v]){
					if(fff==0)fff=v;
					else{
						ops++;w=fff;
						op[ops].x=u;op[ops].y=v;op[ops].z=w;
						du[u]--;du[v]--;
						du[w]--;du[u]--;
						du[w]++;du[v]++;
						del(u,v);del(v,u);
						del(u,w);del(w,u);
						add(v,w);add(w,v);
						fff=0;
						continue;
					}
					for(j=fir[v];j;j=a[j].next){
						w=a[j].v;
						if(w==u)continue;
						if(M[v][w]&&M[u][w]==0){
							ops++;
							op[ops].x=u;op[ops].y=v;op[ops].z=w;
							du[u]--;du[v]--;
							du[w]--;du[v]--;
							du[w]++;du[u]++;
							del(u,v);del(v,u);
							del(v,w);del(w,v);
							add(u,w);add(w,u);
							break;
						}
						else if(M[v][w]&&M[u][w]){
							ops++;
							op[ops].x=u;op[ops].y=v;op[ops].z=w;
							du[u]--;du[v]--;
							du[u]--;du[w]--;
							du[w]--;du[v]--;
							del(u,v);del(v,u);
							del(v,w);del(w,v);
							del(u,w);del(w,u);
							break;
						}
					}
				}
			}
		}
		for(i=1;i<=n;i++){
			if(!VIS[i])kong[++kong[0]]=dfs(i);
		}
		if(kong[0]==n){
			printf("%lld\n",ops);
			for(i=1;i<=ops;i++){
				printf("%lld %lld %lld\n",op[i].x,op[i].y,op[i].z);
			}
		}
		else{
			for(i=1;i<=kong[0];i++){
				if(X!=kong[i]&&Y!=kong[i]){
					ops++;
					op[ops].x=X;op[ops].y=Y;op[ops].z=kong[i];
					Y=kong[i];
				}
			}
			printf("%lld\n",ops);
			for(i=1;i<=ops;i++){
				printf("%lld %lld %lld\n",op[i].x,op[i].y,op[i].z);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
