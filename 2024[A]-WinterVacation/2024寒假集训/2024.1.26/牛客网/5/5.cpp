#include<bits/stdc++.h>
using namespace std;
int T,n,x,y,i;
double zhe[5009],li[5009],a[5009],ans,k,r;
bool cmp(double x,double y){
	return x>y;
}
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		int zhekou=1,lijian=1;
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%lf",&a[i]);
		scanf("%d",&x);
		for(i=1;i<=x;i++)scanf("%lf",&zhe[i]);
		scanf("%d",&y);
		for(i=1;i<=y;i++)scanf("%lf",&li[i]);
		sort(a+1,a+1+n,cmp);
		sort(zhe+1,zhe+1+x);
		sort(li+1,li+1+y,cmp);
		for(i=1;i<=n;i++){
			k=a[i]-a[i]*zhe[zhekou]*0.01;
			r=li[lijian];
			if(k>r&&zhekou<=x){
				ans+=a[i]*zhe[zhekou]*0.01;
				zhekou++;
			}
			else if(lijian<=y){
				ans+=max(a[i]-li[lijian],0.0);
				lijian++;
			}
			else ans+=a[i];
		}
		printf("%.5lf\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
