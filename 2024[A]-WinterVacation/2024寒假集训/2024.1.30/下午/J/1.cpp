#include<bits/stdc++.h>
using namespace std;
struct nod{
	double x,y;
};
struct edg{
	double A,B,C;
};
edg edge[10009];
nod shl[10009],ty[10009];
double r[10009];
double rr[10009];
int i,j,n,m;
double R(edg L,nod x){
	double K=max(L.A*x.x+L.B*x.y+L.C,-(L.A*x.x+L.B*x.y+L.C));
	double l=sqrt((L.A)*(L.A)+(L.B)*(L.B));
	if(l==0)return 0;
	else return K/l;
}
double dian(nod x,nod y){
	return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
void work(nod x,nod y,int bh){
	edge[bh].A=x.y-y.y;
	edge[bh].B=y.x-x.x;
	edge[bh].C=(x.x-y.x)*x.y-(x.y-y.y)*x.x;
}
nod zhong(edg L,nod x,int bh){
	nod ans;
	double kx=L.B*L.B*x.x-L.A*L.C-L.A*L.B*x.y;
	double kxl=(L.A)*(L.A)+(L.B)*(L.B);
	kx/=kxl;
	double ky;
	if(L.B==0)ky=shl[bh].y;
	else ky=-(L.A*kx+L.C)/L.B;
	ans.x=kx;ans.y=ky;
	return ans;
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>m>>n;
	for(i=1;i<=n;i++)r[i]=4e18+7;
	for(i=1;i<=m;i++)scanf("%lf%lf",&ty[i].x,&ty[i].y);
	for(i=1;i<=n;i++)scanf("%lf%lf",&shl[i].x,&shl[i].y);
	for(i=1;i<=m-1;i++){
		work(ty[i],ty[i+1],i);
	}
	for(i=1;i<m;i++){
		for(j=1;j<=n;j++){
			nod z;
			z=zhong(edge[i],shl[j],j);
			if(min(ty[i].x,ty[i+1].x)<=z.x&&z.x<=max(ty[i].x,ty[i+1].x)){
				if(min(ty[i].y,ty[i+1].y)<=z.y&&z.y<=max(ty[i].y,ty[i+1].y)){
					r[j]=min(r[j],R(edge[i],shl[j]));
				}
			}
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			r[j]=min(r[j],dian(shl[j],ty[i]));
		}
	}
	for(i=1;i<=n;i++)printf("%.4lf\n",r[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
