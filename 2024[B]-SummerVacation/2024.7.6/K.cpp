#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,k,j,fir[100009],ans[100009],r[100009],ANS;
struct nod{
	int f,next;
};
int cnt;
nod a[4000009];
bool ff=0;
void add(int u,int v){
	cnt++;
	a[cnt].next=fir[u];
	a[cnt].f=v;
	fir[u]=cnt;
}
void dfs(int u){
	if(ff==1)return;
	int i,k=0;
	for(i=fir[u];i;i=a[i].next){
		if(ff==1)return;
		int v=a[i].f;
		if(ans[v]==0){
			dfs(v);
		}
		else{
			if(ff==1)return;
			if(m>=ans[v]){
				if(m>ans[v])m-=ans[v];
				else{
					ANS=v;
					ff=1;
					return;
				}
			}
			else{
				dfs(v);
			}
		}
		k+=ans[v];
	}
	if(ff==1)return;
	if(k==0)ans[u]=1;
	else ans[u]=k+1;
	if(ff==1)return;
	if(m==1){
		ANS=u;
		ff=1;
		return;
	}
	else{
		m--;
	}
}
signed main(){
	freopen("K.in","r",stdin);freopen("K.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&k);
		for(j=1;j<=k;j++){
			scanf("%lld",&r[j]);
		}
		for(j=k;j>=1;j--){
			add(i,r[j]);
		}
	}
	cin>>m;
	dfs(n);
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
