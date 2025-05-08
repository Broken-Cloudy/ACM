#include<bits/stdc++.h>
using namespace std;
struct nod{
	int bh,dis;
};
struct node{
	int u,v;
};
struct lian{
    int u,v,next;
};
bool f[100009],flag;
lian L[1000009];
node edge[100009];
int cnt,fir[100009],dist,cntedg;
int n,m,i,j,k,vis[1000009];
nod a[100009];
bool cmp(nod x,nod y){
	return x.dis<y.dis;
}
void add(int u,int v){
    L[++cnt].next=fir[u];
    fir[u]=cnt;
    L[cnt].u=u;
    L[cnt].v=v;
}
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i].dis);
		dist=max(dist,a[i].dis);
		a[i].bh=i;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++){
		f[a[i].dis]=1;
		if(f[a[i].dis-1]==0&&a[i].dis!=0){
			printf("-1\n");
			flag=1;
			break;
		}
		else{
			add(a[i].dis,a[i].bh);
		}
	}
	if(flag==0){
		for(i=1;i<=dist;i++){
			int fa=L[fir[i-1]].v;
			for(j=fir[i];j;j=L[j].next){
				cntedg++;
				edge[cntedg].u=fa;
				edge[cntedg].v=L[j].v;
			}
		}
		if(cntedg>m){
			printf("-1\n");
		}
		else{
			for(i=1;i<=dist;i++){
				if(cntedg==m)break;
				for(k=fir[i-1];k;k=L[k].next){
					if(cntedg==m)break;
					if(k==fir[i-1])continue;
					int fa=L[k].v;
					for(j=fir[i];j;j=L[j].next){
						if(cntedg==m)break;
						cntedg++;
						edge[cntedg].u=fa;
						edge[cntedg].v=L[j].v;
					}
				}
				for(k=fir[i];k;k=L[k].next){
					if(cntedg==m)break;
					vis[k]=1;
					for(j=fir[i];j;j=L[j].next){
						if(cntedg==m)break;
						if(vis[j]==1)continue;
						cntedg++;
						edge[cntedg].u=L[k].v;
						edge[cntedg].v=L[j].v;
					}
				}
			}
			if(cntedg==m){
				for(i=1;i<=cntedg;i++){
					printf("%d %d\n",edge[i].u,edge[i].v);
				}
			}
			else{
				printf("-1\n");
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
