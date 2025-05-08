#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,i;
struct nod{
	int u,v,next;
}a[200009];
int cnt,fir[20009],x,y,c_point[20009],ans;
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
int dfn[20009],low[20009],timer,child;
void tarjan(int u,int ancestor){
	int i;
	dfn[u]=low[u]=++timer;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(dfn[v]==0){//δ�����ʹ� 
			tarjan(v,ancestor);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]&&u!=ancestor){
				c_point[u]=1;//ֻҪ��һ������뾭��u��u��������� 
			}
			if(u==ancestor){//��ʾ���ancestor��һ������ 
				child++;
			}
		}
		else low[u]=min(low[u],dfn[v]);//���ʵ��Ѿ��ѹ��ĵ��� 
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	for(i=1;i<=n;i++){
		child=0;
		if(dfn[i]==0)tarjan(i,i);
		if(child>=2)c_point[i]=1;
	}
	for(i=1;i<=n;i++)if(c_point[i])ans++;
	cout<<ans<<endl;
	for(i=1;i<=n;i++){
		if(c_point[i])printf("%lld ",i);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
