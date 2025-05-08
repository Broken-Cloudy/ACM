#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next,len;
}edg[1200009];
struct node{
	int bh,val;
}t;
struct cmp{
	bool operator()(node x,node y){
		return x.val<y.val;
	}
};
priority_queue<node,vector<node>,cmp>q;
int fir[600009],cnt,vis[600009];
int T,n,k,a[300009],i,b[600009],ans,op,u,v,w,len,r;
char c[300009];
void add(int x,int y,int Len){
	cnt++;
	edg[cnt].next=fir[x];
	edg[cnt].u=x;edg[cnt].v=y;edg[cnt].len=Len;
	fir[x]=cnt;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);getchar();
		for(i=1;i<=n;i++)c[i]=getchar();
		ans=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(c[i]=='B'){
				ans+=a[i];
				a[i]=-a[i];
			}
			fir[i]=fir[i+n]=0;vis[i]=vis[i+n]=0;
		}
		if(k==0){
			printf("%lld\n",ans);
			continue;
		}
		b[0]=0;b[++b[0]]=a[1];
		for(i=2;i<=n;i++){
			if(c[i]==c[i-1])b[b[0]]+=a[i];
			else b[++b[0]]=a[i];
		}
		cnt=0;
		while(!q.empty())q.pop();
		for(i=1;i<=b[0];i++){
			if(b[i]<0){
				if(i+2<=b[0]){
					add(i,i+2,b[i+1]);
					add(i+2,i,b[i+1]);
				}
				t.bh=i;t.val=b[i];
				q.push(t);
			}
		}
		op=q.size()-k;
		while(!q.empty()&&op){
			t=q.top();q.pop();
			if(vis[t.bh]==1)continue;
			op--;vis[t.bh]=1;
			int L1,L2;
			u=t.bh;len=9999999999999LL;v=0;w=0;r=0;
			for(i=fir[u];i;i=edg[i].next){
				if(edg[i].len<=len&&vis[edg[i].v]==0){
					v=edg[i].v;
					len=edg[i].len;
				}
			}
			if(len+b[t.bh]>=0||v==0)continue;
			for(i=fir[u];i;i=edg[i].next){
				if(edg[i].v!=v&&vis[edg[i].v]==0){
					r=edg[i].v;L1=edg[i].len;
				}
			}
			for(i=fir[v];i;i=edg[i].next){
				if(edg[i].v!=u&&vis[edg[i].v]==0){
					w=edg[i].v;L2=edg[i].len;
				}
			}
			b[0]++;t.bh=b[0];t.val=b[u]+b[v]+len;
			vis[u]=1;vis[v]=1;b[b[0]]=t.val;q.push(t);
			if(r)add(r,b[0],L1),add(b[0],r,L1);
			if(w)add(w,b[0],L2),add(b[0],w,L2);
		}
		while(!q.empty()){
			t=q.top();q.pop();
			if(vis[t.bh]==1)continue;
			else ans+=t.val;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
