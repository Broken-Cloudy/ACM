#include<bits/stdc++.h>
using namespace std;
string sss;
char c;
int n,m,vis[109],i,x,Same,Right,j;
struct nod{
	string num;
	int same,right;
};
nod a[109];
queue<string>q;
queue<string>qq;
bool cmp(nod x,nod y){
	if(x.same==y.same)return (x.right+x.same)<(y.right+y.same);
	return x.same>y.same;
}
void dfs(int x,string ss){
	int i;
	char c;
	if(x==0){
		Same=Right=0;
		string s0=ss;
		int vis[19];
		memset(vis,0,sizeof(vis));
		for(j=0;j<m;j++)vis[s0[j]-'0']=1;
		for(j=0;j<m;j++){
			if(s0[j]==a[1].num[j])Same++;
			else if(vis[a[1].num[j]-'0']==1)Right++;
		}
		if(Same==a[1].same&&Right==a[1].right){
			q.push(s0);
		}
		return;
	}
	else{
		for(i=0;i<=9;i++){
			if(vis[i]==0){
				c=i+48;
				vis[i]=1;
				dfs(x-1,ss+c);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("9b.in","r",stdin);freopen("9b.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i].num>>a[i].same>>a[i].right;
	}
	sort(a+1,a+1+n,cmp);
	for(i=0;i<=9;i++){
		vis[i]=1;
		c=i+48;
		sss+=c;
		dfs(m-1,sss);
		sss.clear();
		vis[i]=0;
	}
	for(i=2;i<=n;i++){
		if(qq.empty()){//qq¿Õ 
			while(!q.empty()){
				Same=Right=0;
				string s0=q.front();
				q.pop();
				int vis[19];
				memset(vis,0,sizeof(vis));
				for(j=0;j<m;j++)vis[s0[j]-'0']=1;
				for(j=0;j<m;j++){
					if(s0[j]==a[i].num[j])Same++;
					else if(vis[a[i].num[j]-'0']==1)Right++;
				}
				if(Same==a[i].same&&Right==a[i].right){
					qq.push(s0);
				}
			}
		}
		else{
			while(!qq.empty()){
				Same=Right=0;
				string s0=qq.front();
				qq.pop();
				int vis[19];
				memset(vis,0,sizeof(vis));
				for(j=0;j<m;j++)vis[s0[j]-'0']=1;
				for(j=0;j<m;j++){
					if(s0[j]==a[i].num[j])Same++;
					else if(vis[a[i].num[j]-'0']==1)Right++;
				}
				if(Same==a[i].same&&Right==a[i].right){
					q.push(s0);
				}
			}
		}
		if(q.size()==1||qq.size()==1){
			if(q.size()==1)cout<<q.front();
			else cout<<qq.front();
			break;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
