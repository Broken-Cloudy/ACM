#include<bits/stdc++.h>
using namespace std;
int n,i;
double b[100010],a[100010],zhong;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lf",&a[i]);
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	if(n==1)printf("%.1lf\n",0);
	else if(n%2==0){
		zhong=(a[n/2]+a[n/2+1])/2;
		for(i=1;i<=n;i++){
			if(b[i]>zhong){
				printf("%.1lf\n",a[n/2]);
			}
			else printf("%.1lf\n",a[n/2+1]);
		}
	}
	else{
		zhong=a[n/2+1];
		for(i=1;i<=n;i++){
			if(b[i]>zhong){
				printf("%.1lf\n",(a[n/2]+a[n/2+1])/2);
			}
			else if(b[i]<zhong){
				printf("%.1lf\n",(a[n/2+2]+a[n/2+1])/2);
			}
			else{
				printf("%.1lf\n",(a[n/2+2]+a[n/2])/2);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
