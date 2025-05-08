#include<iostream>
#include<cstdio>
using namespace std;
int i,j,T;
double n,m;
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	for(i=1;i<=T;i++){
		cin>>n>>m;
		double k;
		long long ans;
		if(n>m){//×êÊ¯¶à 
			k=(2*m-n)/3;
			if(k<=0){
				printf("%.0lf\n",m);
			}
			else{
				ans=2*k+(m-3*k);
				printf("%lld\n",ans);
			}
		}
		else{
			k=(2*n-m)/3;
			if(k<=0){
				printf("%.0lf\n",n);
			}
			else{
				ans=2*k+(n-3*k);
				printf("%lld\n",ans);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
