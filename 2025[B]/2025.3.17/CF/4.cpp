#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
struct nod{
	int x,y;
}d[200009],t;
queue<nod>q;
int cnt;
int T,x,y,i,ans,j,a[109],f[69][69],anss[129],F[69][69];
void dfs(int F,int x,int y){
	int i;
	if(x==0&&y==0)return;
	if(F>=1000){
		i=F/1000;
		dfs(f[x-a[i]][y],x-a[i],y);
		anss[++anss[0]]=a[i];
	}
	else{
		i=F;
		dfs(f[x][y-a[i]],x,y-a[i]);
		anss[++anss[0]]=a[i];
	}
}
int check(int u,int v){
	int i,j,kk=0;
	if(u==0&&v==0){
		return kk;
	}
	if(f[u][v]){
		anss[0]=0;
		dfs(f[u][v],u,v);
		for(i=1;i<=anss[0];i++){
			kk+=(1LL<<anss[i]);
		}
		return kk;
	}
	else return (1LL<<61);
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	for(i=1;i<=109;i++)a[i]=i;
	cnt++;d[cnt].x=0;d[cnt].y=0;
	for(i=1;i<=61;i++){//500
		for(j=1;j<=cnt;j++){//150000
			x=d[j].x;y=d[j].y;
			if(x+a[i]<=61){
				if(f[x+a[i]][y]==0){
					f[x+a[i]][y]=i*1000;
					t.x=x+a[i];t.y=y;q.push(t);
				}
			}
			if(y+a[i]<=61){
				if(f[x][y+a[i]]==0){
					f[x][y+a[i]]=i;
					t.x=x;t.y=y+a[i];q.push(t);
				}
			}
		}
		while(!q.empty()){
			t=q.front();q.pop();
			d[++cnt]=t;
		}
	}
	for(i=60;i>=0;i--){
		for(j=60;j>=0;j--){
			F[i][j]=check(i,j);
		}
	}
	while(T--){
		ans=(1LL<<62);
		scanf("%lld%lld",&x,&y);
		for(i=60;i>=0;i--){
			for(j=60;j>=0;j--){
				if((x>>i)==(y>>j)){
					ans=min(ans,F[i][j]);
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
