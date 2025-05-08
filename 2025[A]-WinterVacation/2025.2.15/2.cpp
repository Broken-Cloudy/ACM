#include<bits/stdc++.h>
#define int long long
using namespace std;
int fir[100009],cnt,n,x,y,i,f[100009],ans[100009],vis[100009],kk,ANS;
struct nod{
	int u,v,next;
}a[200009];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
void dfs(int u,int deep){
	int i;
	vis[u]=1;
	if(deep>ANS){
		ANS=deep;
		ans[0]=0;
		ans[++ans[0]]=u;
	}
	else if(deep==ANS){
		ans[++ans[0]]=u;
	}
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			dfs(v,deep+1);
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&y);
		if(y==-1){
			kk=i;
			continue;
		}
		x=i;
		add(x,y);add(y,x);
	}
	dfs(kk,1);
	sort(ans+1,ans+1+ans[0]);
	cout<<ANS<<endl;
	for(i=1;i<=ans[0];i++){
		if(i==ans[0])printf("%lld\n",ans[i]);
		else printf("%lld ",ans[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
