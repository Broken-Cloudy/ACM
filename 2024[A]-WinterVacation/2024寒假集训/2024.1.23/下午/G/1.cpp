#include<iostream>
#include<cstdio>
using namespace std;
double a,b,c,d,x,y,midx,midy;
bool f;
bool check(double x,double y){
	double mx=(x+a)/2;
	double my=(y+b)/2;
	if((midx-x)*(a-c)+(midy-y)*(b-d)==0){
		if((mx-c)*(x-a)+(my-d)*(y-b)==0){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>a>>b>>c>>d;
	midx=(a+c)/2;midy=(b+d)/2;
	for(x=-3000;x<=3000;x++){
		for(y=-3000;y<=3000;y++){
			if(check(x,y)==1&&(x!=a||x!=b)&&(y!=c||y!=d)){
				printf("%.0lf %.0lf\n",x,y);
				f=1;
			}
		}
	}
	if(f==0){
		cout<<-1<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
