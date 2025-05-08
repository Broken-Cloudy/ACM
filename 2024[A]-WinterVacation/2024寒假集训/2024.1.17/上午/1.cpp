#include<bits/stdc++.h>
using namespace std;
struct nod{
	double x,y,cita;
};
double x,y,ans;
int n,cnt,i,d;
nod a[100009],maxp,zhan[100009];
bool cmp(nod x,nod y){
	if(x.cita==y.cita){
		if(x.x==y.x)return x.y<y.y;
		else return x.x<y.x;
	}
	else return x.cita<y.cita;
	
}
bool flag;//flag==1左转 flag==0右转 
int check(nod p0,nod p1,nod p2){
	if((p2.x-p0.x)*(p1.y-p0.y)-(p1.x-p0.x)*(p2.y-p0.y)>0){//右转 
		return 0;
	}
	else if((p2.x-p0.x)*(p1.y-p0.y)-(p1.x-p0.x)*(p2.y-p0.y)<0){//左转 
		return 1;
	}
	else{//直行 
		return -1;
	}
}
double length(nod x,nod y){
	return sqrt((y.y-x.y)*(y.y-x.y)+(y.x-x.x)*(y.x-x.x));
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;maxp.y=10000009.00;
	for(i=1;i<=n;i++){
		scanf("%lf%lf",&x,&y);
		if(y<maxp.y||y==maxp.y&&x>=maxp.x){
			if(maxp.y!=10000009){
				a[++cnt].x=maxp.x;
				a[cnt].y=maxp.y;
			}
			maxp.x=x;
			maxp.y=y;
		}
		else{
			a[++cnt].x=x;
			a[cnt].y=y;
		}
	}
	for(i=1;i<=cnt;i++){
		a[i].cita=atan2(a[i].y-maxp.y,a[i].x-maxp.x);
	}
	sort(a+1,a+1+cnt,cmp);
	zhan[++d]=maxp;
	zhan[++d]=a[1];zhan[++d]=a[2];
	if(check(zhan[1],zhan[2],zhan[3])==1)flag=1;//flag==1左转
	else flag=0;//flag==0右转 
	ans+=length(zhan[1],zhan[2]);ans+=length(zhan[2],zhan[3]);
	for(i=3;i<=cnt;i++){
		zhan[++d]=a[i];
		while(true){
			if(check(zhan[d-2],zhan[d-1],zhan[d])==flag||check(zhan[d-2],zhan[d-1],zhan[d])==-1){
				ans+=length(zhan[d-1],zhan[d]);
				break;
			}
			else{
				ans-=length(zhan[d-2],zhan[d-1]);
				swap(zhan[d],zhan[d-1]);d--;
			}
		}
	}
	ans+=length(zhan[d],zhan[1]);
	//for(i=1;i<=cnt;i++)printf("%lf %lf %lf\n",a[i].x,a[i].y,a[i].cita);
	if(n==1)printf("%.2lf\n",0);
	else if(n==2)printf("%.2lf\n",length(zhan[1],zhan[2]));
	else printf("%.2lf\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
