#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,x,y,T,vis[809][809],i,j,cnt,ans;
int point[809][809];
char c,a[809][809];
bool ff=0;
void solve(){
	int i,j;
	printf("Yes\n");
	for(i=1;i<=n;i++){//µã 
		for(j=1;j<=m;j++){
			putchar(a[i][j]);
		}
		putchar('\n');
	}
}
bool change(int x,int y,int u,int v){
	if((x>1&&y>1&&x<n+1&&y<m+1&&vis[x][y]==0)||(u>1&&v>1&&u<n+1&&v<m+1&&vis[u][v]==0)){
		vis[x][y]=1;vis[u][v]=1;
		return 1;
	}
	else return 0;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld%lld",&n,&m,&k);
		scanf("%lld%lld",&x,&y);
		getchar();c=getchar();
		for(i=0;i<=n;i++)for(j=0;j<=m;j++)vis[i][j]=0,point[i][j]=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if((i+j)%2==0){
					a[i][j]='A';
				}
				else a[i][j]='B';
			}
		}
		if(a[x][y]!=c){
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					if((i+j)%2==0)a[i][j]='B';
					else a[i][j]='A';
				}
			}
		}
		cnt=0;ans=0;
		for(i=1;i<=n+1;i++){//µã 
			for(j=1;j<=m+1;j+=2){
				if(j==1){
					if(a[i][j]=='A'||a[i-1][j]=='B')j=1;
					else j=2;
				}
				cnt++;
			}
		}
		if(cnt<k){
			printf("No\n");
			continue;
		}
		ff=0;
		for(i=0;i<=n;i++)for(j=0;j<=m;j++)vis[i][j]=0;
		for(i=1;i<=n;i++){
			if(ff==1)break;
			for(j=1;j<=m;j++){
				if(ff==1)break;
				if(cnt-ans==k){
					solve();
					ff=1;
				}
				if(ff==1)break;
				if(a[i][j]=='A'){
					if(change(i,j,i+1,j+1)==0)continue;
					ans++;
					a[i][j]='B';
				}
				else{
					if(change(i,j+1,i+1,j)==0)continue;
					ans++;
					a[i][j]='A';
				}
				if(ff==1)break;
				if(cnt-ans==k){
					solve();
					ff=1;
				}
				if(ff==1)break;
			}
		}
		if(ff==0){
			printf("No\n");
			continue;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

