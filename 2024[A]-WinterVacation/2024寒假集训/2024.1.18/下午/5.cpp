#include<bits/stdc++.h>
using namespace std;
struct nod{
	int x,y,z;
};
nod p[10009];
int cnt;
int x,y,z,v,n,m,h,q,i,op;
long long a[102][102][102];
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>m>>h>>q;
	for(int o=1;o<=q;o++){
		cin>>op;
		if(op==1){
			scanf("%d%d%d%d",&x,&y,&z,&v);
			if(a[x][y][z]==0){
				p[++cnt].x=x;
				p[cnt].y=y;
				p[cnt].z=z;
			}
			a[x][y][z]+=v;
		}
		else{
			int x1,x2,y1,y2,z1,z2;
			long long ans=0;
			scanf("%d%d%d",&x1,&y1,&z1);
			scanf("%d%d%d",&x2,&y2,&z2);
			for(i=1;i<=cnt;i++){
				if(p[i].x>=min(x1,x2)&&p[i].x<=max(x1,x2)){
					if(p[i].y>=min(y1,y2)&&p[i].y<=max(y1,y2)){
						if(p[i].z>=min(z1,z2)&&p[i].z<=max(z1,z2)){
							ans+=a[p[i].x][p[i].y][p[i].z];
						}
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
