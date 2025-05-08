#include<bits/stdc++.h>
using namespace std;
int T,n,m,i,cnt,u,v;
struct nod{
	int bh,score;
	int u,v;
};
nod a[1009],com[1009];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d%d",&n,&m);cnt=0;
		for(i=1;i<=n;i++)scanf("%d",&a[i].score),a[i].bh=i;
		for(i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			if(u==1){
				a[1].score+=3;
				a[v].score-=3;
			}
			else if(v==1){
				a[1].score+=3;
				a[u].score-=3;
			}
			else{
				com[++cnt].u=u;
				com[++cnt].v=v;
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
