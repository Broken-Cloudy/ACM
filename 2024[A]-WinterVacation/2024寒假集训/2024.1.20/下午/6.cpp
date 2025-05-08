#include<iostream>
#include<cstdio>
#define ll long long
ll n,m,ans,D;
using namespace std;
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n>>m;
	while(ans<n){
		D++;ans+=m;
		if(m==1)break;
		else if(m%2==0){
			m/=2;
		}
		else if(m%1==0){
			m=m*3+1;
		}
	}
	if(ans>=n){
		printf("%lld\n",D);
	}
	else{
		int re=n-ans;
		if(re==0){
			printf("%lld\n",D);
		}
		else if(re<=4&&re>0){
			printf("%lld\n",D+1);
		}
		else if(re<=6&&re>4){
			printf("%lld\n",D+2);
		}
		else{
			int yu=re/7;
			D+=yu*3;
			re-=re/7;
			if(re==0){
				printf("%lld\n",D);
			}
			else if(re<=4&&re>0){
				printf("%lld\n",D+1);
			}
			else if(re<=6&&re>4){
				printf("%lld\n",D+2);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
