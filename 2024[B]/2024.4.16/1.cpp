#include<bits/stdc++.h>
using namespace std;
int i,n;
struct nod{
	double per,liang,jia;
}a[1000010];
bool cmp(nod x,nod y){
	return x.per>y.per;
}
double m,ans;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%lf",&a[i].liang);
	}
	for(i=1;i<=n;i++){
		scanf("%lf",&a[i].jia);
		a[i].per=a[i].jia/a[i].liang;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++){
		if(m==0)break;
		if(m<=a[i].liang){
			ans+=a[i].per*m;
			m=0;
		}
		else{
			m-=a[i].liang;
			ans+=a[i].jia;
		}
	}
	printf("%.2lf\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
