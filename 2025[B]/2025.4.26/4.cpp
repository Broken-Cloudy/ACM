#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1000000007LL;
int T,n,m,k,x[500009],y[500009],i,j,pp,X,Y,f[1009][1009],xmin,xmax,ymin,ymax;
int FF,ans,p1_2=500000004LL,p3_2=500000005LL,u,v,q,p;
map<int,map<int,int>>M;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);FF=0;M.clear();ans=1;
		for(i=1;i<=k+1;i++){
			scanf("%lld%lld",&x[i],&y[i]);
			f[x[i]][y[i]]=1;
		}
		for(pp=1;pp<=k;pp++){
			xmin=min(x[pp],x[pp+1]);xmax=max(x[pp],x[pp+1]);
			ymin=min(y[pp],y[pp+1]);ymax=max(y[pp],y[pp+1]);
			if(xmax-xmin+ymax-ymin==2){
				if(xmax-xmin==2||ymax-ymin==2){
					if(xmax-xmin==2){X=(xmax+xmin)/2;Y=ymin;}
					else{X=xmin;Y=(ymax+ymin)/2;}
					if(M[X][Y]==1)ans*=0;
					else if(M[X][Y]>1)ans*=p1_2;
					else ans*=1;
					M[X][Y]=1;
				}
				else{
					if(x[pp]<x[pp+1]&&y[pp]<y[pp+1]){
						u=x[pp];v=y[pp]+1;
						X=x[pp]+1;Y=y[pp];
					}
					else if(x[pp]>x[pp+1]&&y[pp]>y[pp+1]){
						u=x[pp+1];v=y[pp+1]+1;
						X=x[pp+1]+1;Y=y[pp+1];
					}
					else{
						if(x[pp]<x[pp+1]){
							u=x[pp]+1;v=y[pp];
							X=x[pp];Y=y[pp]-1;
						}
						else{
							u=x[pp+1]+1;v=y[pp+1];
							X=x[pp+1];Y=y[pp+1]-1;
						}
					}
					if(M[u][v]==1&&M[X][Y]==1){
						ans*=0;
					}
					else if(M[u][v]==1&&M[X][Y]>1||M[u][v]>1&&M[X][Y]==1){
						ans*=p1_2;
						if(M[X][Y]>1){
							p=M[X][Y]/1000;q=M[X][Y]%1000;
							M[X][Y]=1;M[p][q]=1;
						}
						else{
							p=M[u][v]/1000;q=M[u][v]%1000;
							M[u][v]=1;M[p][q]=1;
						}
					}
					else if(M[u][v]==1&&M[X][Y]>1||M[u][v]>1&&M[X][Y]==1){
						
					}
					else if(M[u][v]==0&&M[X][Y]==0){
						ans*=2;
						M[X][Y]=u*1000+v;M[u][v]=X*1000+Y;
						
					}
				}
			}
			else FF=1;
		}
		if(FF==1)printf("0\n");
		else printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
