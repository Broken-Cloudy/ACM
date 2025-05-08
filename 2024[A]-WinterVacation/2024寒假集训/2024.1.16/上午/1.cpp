#include<iostream>
#include<cstdio>
using namespace std;
int n,i;
long double x,y,ans;
struct nod{
	long double x,y;
};
long double S(nod p1,nod p2,nod p3){
	return ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))/2;
}
nod a[120];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	if(n==1||n==2){
		printf("%d\n",0);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	for(i=1;i<=n;i++){
		scanf("%llf%llf",&x,&y);
		a[i].x=x;a[i].y=y;
	}
	for(i=2;i<n;i++){
		ans+=S(a[1],a[i],a[i+1]);
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
} 
