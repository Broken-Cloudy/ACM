#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int des[100009],n,x,i,RMB=0;
const int inf=1e9+7;
struct nod{
	int bh,dis;
};
nod a[100009];
bool vis[100009];
struct cmp{
	bool operator()(nod x,nod y){
		return x.dis>y.dis;
	}
};
priority_queue<nod,vector<nod>,cmp>q;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>x;
	for(i=0;i<n;i++){
		scanf("%d",&des[i]);
	}
	for(i=0;i<n;i++){
		a[i].bh=i;
		a[i].dis=inf;
	}
	a[0].dis=0;
	q.push(a[0]);
	while(!q.empty()){
		nod node=q.top();q.pop();
		int t=node.bh;
		if(vis[t]==1)continue;
		else vis[t]=1;
		int now=(des[t]+t)%n;
		int ans=1;
		while(now<=x+n){
			if(vis[now%n]==1){
				ans++;now++;
			}
			else{
				if(ans+a[t].dis<a[now%n].dis&&ans+a[t].dis<a[x].dis){
					a[now%n].dis=ans+a[t].dis;
					nod add;
					add.bh=now;add.dis=a[now%n].dis;
					q.push(add);
					ans++;now++;
				}
				else break;
			}
		}
	}
	printf("%d",a[x].dis);
	fclose(stdin);fclose(stdout);
	return 0;
}
