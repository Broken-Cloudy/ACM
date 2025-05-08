#include<bits/stdc++.h>
using namespace std;
long long n,k,i,a[100009],zhan[100009],d,h,ans=1;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	zhan[++h]=a[1];d=1;
	for(i=2;i<=n;i++){
		while((a[i]-zhan[d])>k&&d<=h)d++;
		zhan[++h]=a[i];
		ans=max(ans,h-d+1);
	}
	double c=ans,d=n;
	double anss=c/d;
	printf("%.6lf\n",anss);
	fclose(stdin);fclose(stdout);
	return 0;
}
