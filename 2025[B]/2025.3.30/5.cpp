#include<bits/stdc++.h>
#define int long long
using namespace std;
queue<int>q;
int N,i,a[39],cnt,tree[98],ans[98];
void dfs(int node){
	int zuo=node*2;
	int you=node*2+1;
	cnt++;
	tree[node]=a[cnt];
	if(you<=N){
		dfs(you);
	}
	if(zuo<=N){
		dfs(zuo);
	}
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=N/2;i++)swap(a[i],a[N-i+1]);//¸ùÓÒ×ó 
	dfs(1);
	q.push(1);
	while(!q.empty()){
		int t=q.front();q.pop();
		ans[++ans[0]]=tree[t];
		int zuo=t*2;
		int you=t*2+1;
		if(zuo<=N){
			q.push(zuo);
		}
		if(you<=N){
			q.push(you);
		}
	}
	for(i=1;i<=ans[0];i++){
		if(i==ans[0])printf("%lld\n",ans[i]);
		else printf("%lld ",ans[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
