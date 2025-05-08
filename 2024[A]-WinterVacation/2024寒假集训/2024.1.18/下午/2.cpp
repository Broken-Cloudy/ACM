#include<bits/stdc++.h>
using namespace std;
long long n,i;
struct nod{
	long double V,W,per;
};
nod a[100009];
double ans;
long double m;
bool cmp(nod x,nod y){
	return x.per>y.per;
}
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%llf%llf",&a[i].W,&a[i].V);
		a[i].per=a[i].V/a[i].W;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++){
		if(m>a[i].W){
			ans+=a[i].V;
			m-=a[i].W;
		}
		else{
			ans+=a[i].per*m;
			break;
		}
	}
	printf("%.4lf\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
