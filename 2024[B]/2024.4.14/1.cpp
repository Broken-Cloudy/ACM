#include<bits/stdc++.h>
using namespace std;
const int inf=1000000009;
int N,M,S,D,w[609],i,j,k,a[609][609],u,v,len,path[609][609],ans,dis,f[609][609],sum[609][609];
int ru[609],cnt;
void dfs(int u,int v){
	if(path[u][v]==u){
		cout<<u<<' ';
		return;
	}
	dfs(u,path[u][v]);
	cout<<u<<' ';
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>N>>M>>S>>D;
	for(i=0;i<N;i++){
		scanf("%d",&w[i]);
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			a[i][j]=a[j][i]=inf;
		}
	}
	//初始化路径
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i!=j&&a[i][j]!=inf){
				path[i][j]=i;
			}
			else path[i][j]=-1;//这里有零，初始化不能是0 
		}
	}
	for(i=0;i<N;i++)a[i][i]=0,f[i][i]=w[i];
	for(i=0;i<M;i++){
		scanf("%d%d%d",&u,&v,&len);
		a[u][v]=a[v][u]=len;
	}
	for(k=0;k<N;k++){
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(a[i][k]+a[k][j]<=a[i][j]){
					a[i][j]=a[i][k]+a[k][j];
					path[i][j]=path[k][j];
				}
			}
		}
	}
	cout<<ans<<endl;
	dfs(S,D);
	cout<<D<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
