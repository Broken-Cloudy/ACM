#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
struct nod{
	int next,u,v;
};
struct Time{
	int in_time,out_time;
};
Time A[300009];
nod a[600009];
int fir[300009],cnt,vis[300009],x,y,num,timer,fa[300009];
void add(int u,int v){
	cnt++;
	a[cnt].next=fir[u];
	a[cnt].u=u;a[cnt].v=v;
	fir[u]=cnt;
}
int T,i,k,n,q,b[300009],p[300009];
void dfs(int x){
	int i;
	vis[x]=1;
	A[x].in_time=++timer;
	for(i=fir[x];i;i=a[i].next){
		int y=a[i].v;
		if(vis[y]==0){
			dfs(y);
		}
	}
	A[x].out_time=++timer;
}
//fa(p[i+1])应该是p[i]的祖先(包括父亲) 
bool checker2(int x){//位于p[i+1]位
	if(x==1||p[x]==1){
		if(p[x]==1&&p[x]==1)return 1;
		else return 0;
	}
	else{
		int ancestor=fa[p[x]];
		if(A[ancestor].in_time<=A[p[x-1]].in_time&&A[ancestor].out_time>=A[p[x-1]].out_time){
			return 1;//满足条件(等于号包括了父亲) 
		}
		else return 0;//不满足 
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&q);cnt=0;
		for(i=1;i<=n;i++)fir[i]=0,vis[i]=0;
		for(i=2;i<=n;i++){
			scanf("%lld",&k);
			add(i,k);add(k,i);
			fa[i]=k;
		}
		timer=0;
		dfs(1);
		for(i=1;i<=n;i++){
			scanf("%lld",&p[i]);
		}
		num=0;
		for(i=1;i<=n;i++){
			num+=checker2(i);
		}
		while(q--){
			scanf("%lld%lld",&x,&y);
			set<int>check;//自动去重 
			check.insert(x);check.insert(y);
			if(x-1>=1)check.insert(x-1);
			if(x+1<=n)check.insert(x+1);
			if(y-1>=1)check.insert(y-1);
			if(y+1<=n)check.insert(y+1);
			//先消除原来的记录 
			for(set<int>::iterator i=check.begin();i!=check.end();i++){
				int r=*i;
				num-=checker2(r);
			}
			swap(p[x],p[y]);
			//再加回来现在的记录 
			for(set<int>::iterator i=check.begin();i!=check.end();i++){
				int r=*i;
				num+=checker2(r);
			}
			if(num==n)printf("YES\n");
			else printf("NO\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
