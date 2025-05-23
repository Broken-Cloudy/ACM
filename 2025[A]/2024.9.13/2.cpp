#include<bits/stdc++.h>
#define int long long
#define PI acos(-1);
using namespace std;
struct nod{
	double x,y;
};
nod a[200009];
int i,j,n;
double dis=1e19;
double DIS(int i,int j){
	return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
}
bool cmp(nod x,nod y){
	return x.x<y.x;
}
void around(double dd){
	double x0=0.0,y0=0.0;
	dd=dd/180.0*PI;
	for(i=1;i<=n;i++){
		double x=a[i].x,y=a[i].y;//转前点 
		double xn=(x-x0)*cos(dd)-(y-y0)*sin(dd)+x0;
		double yn=(y-y0)*cos(dd)+(x-x0)*sin(dd)+y0;
		a[i].x=xn;a[i].y=yn;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++){
		for(j=i+1;j<=i+6;j++){//卡常数 
			dis=min(dis,DIS(i,j));
		}
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lf%lf",&a[i].x,&a[i].y);
	}
	around(0);
	around(rand()%360);
	around(rand()%360);
	printf("%.4lf\n",dis);
	fclose(stdin);fclose(stdout);
	return 0;
}
