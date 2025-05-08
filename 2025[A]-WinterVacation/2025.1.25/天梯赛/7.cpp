#include<bits/stdc++.h>
using namespace std;
int a[109][109],i,j,m,n,f[109][109],x,y,step,k,u,v,ans,S[10009],anss;
struct nod{
	int bh,time;
}b[10009];
struct node{
	int x,y,step;
}t;
queue<node>q;
bool cmp(nod x,nod y){
	return x.time<y.time;
}
signed main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>m>>n;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==2){
				x=i;y=j;
			}
		}
	}
	for(i=1;i<=100;i++)for(j=1;j<=100;j++)f[i][j]=-1;f[x][y]=0;
	t.x=x;t.y=y;t.step=0;q.push(t);
	while(!q.empty()){
		t=q.front();q.pop();
		u=t.x;v=t.y;step=t.step;
		if(f[u][v]>0)continue;
		if(a[u][v]==0)continue;
		if(u>=1&&u<=m&&v>=1&&v<=n){
			f[u][v]=step;
		}
		else continue;
		t.x=u+1;t.y=v;t.step=step+1;q.push(t);
		t.x=u;t.y=v+1;t.step=step+1;q.push(t);
		t.x=u-1;t.y=v;t.step=step+1;q.push(t);
		t.x=u;t.y=v-1;t.step=step+1;q.push(t);
	}
	f[x][y]=0;
	cin>>k;
	for(i=1;i<=k;i++){
		scanf("%d%d",&v,&u);
		b[i].bh=i;
		if(f[u][v]!=-1){
			b[i].time=f[u][v];
			S[f[u][v]]++;
		}
		else b[i].time=9999999;
	}
	sort(b+1,b+1+k,cmp);
	for(i=1;i<=k;i++){
		if(b[i].time!=9999999){
			if(S[b[i].time]==1){
				ans=b[i].bh;
				anss=b[i].time;
				break;
			}			
		}
	}
	if(ans==0)printf("No winner.\n");
	else printf("%d %d\n",ans,anss);
	fclose(stdin);fclose(stdout);
	return 0;
}
