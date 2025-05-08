#include<bits/stdc++.h>
using namespace std;
struct nod{
	int x,y;
}d[200009],t;
queue<nod>q;
int n,m,a[509],X,x,y,ans1[509],ans2[509],i,j,cnt;
int f[109][10009];
void dfs(int F,int x,int y){
	int i;
	if(x==0&&y==0)return;
	if(F>=1000){
		i=F/1000;
		dfs(f[x-a[i]][y],x-a[i],y);
		ans1[++ans1[0]]=a[i];
	}
	else{
		i=F;
		dfs(f[x][y-a[i]],x,y-a[i]);
		ans2[++ans2[0]]=a[i];
	}
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	cnt++;d[cnt].x=0;d[cnt].y=0;
	for(i=1;i<=n;i++){//500
		for(j=1;j<=cnt;j++){//150000
			x=d[j].x;y=d[j].y;
			if(x+a[i]<=min(100,10000/max(1,y)+1)){
				if(f[x+a[i]][y]==0){
					f[x+a[i]][y]=i*1000;//hash x
					t.x=x+a[i];t.y=y;q.push(t);
				}
			}
			if(y+a[i]<=min(10000,10000/max(1,x)+1)){
				if(f[x][y+a[i]]==0){
					f[x][y+a[i]]=i;//hash y
					t.x=x;t.y=y+a[i];q.push(t);
				}
			}
		}
		while(!q.empty()){
			t=q.front();q.pop();
			d[++cnt]=t;
		}
	}
	while(m--){//1000
		scanf("%d",&X);
		ans1[0]=ans2[0]=0;
		for(x=1;x*x<=X;x++){//100
			if(X%x==0){
				y=X/x;
				if(f[x][y]){//500
					dfs(f[x][y],x,y);
					break;
				}
			}
		}
		if(ans1[0]>0&&ans2[0]>0){
			printf("YES\n");
			printf("%d %d\n",ans1[0],ans2[0]);
			for(i=1;i<=ans1[0];i++){
				if(i==ans1[0])printf("%d\n",ans1[i]);
				else printf("%d ",ans1[i]);
			}
			for(i=1;i<=ans2[0];i++){
				if(i==ans2[0])printf("%d\n",ans2[i]);
				else printf("%d ",ans2[i]);
			}
		}
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
