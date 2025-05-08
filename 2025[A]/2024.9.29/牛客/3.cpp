#include<bits/stdc++.h>
#define int long long
using namespace std;
const double pi=acos(-1);
int n,k,i,cnt;
double d(double x,double y){
	return sqrt(x*x+y*y);
}
struct nod{
	double x,y,r,S;
	double ans;
};
nod yuan[100009],pp[100009];
double ANS=0;
bool cmp(nod x,nod y){
	return x.ans>y.ans;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%lf%lf%lf",&yuan[i].x,&yuan[i].y,&yuan[i].r);
		yuan[i].S=pi*yuan[i].r*yuan[i].r;
		if(d(yuan[i].x,yuan[i].y)<yuan[i].r){
			cnt++;
			pp[cnt]=yuan[i];
			pp[cnt].ans=(yuan[i].r-d(yuan[i].x,yuan[i].y))*yuan[i].S;
		}
	}
	sort(pp+1,pp+1+cnt,cmp);
	while(cnt>k){
		ANS+=pp[cnt].ans;
		cnt--;
	}
	printf("%.9lf\n",ANS);
	fclose(stdin);fclose(stdout);
	return 0;
}
