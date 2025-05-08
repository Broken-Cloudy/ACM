#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long x,a,b,ans;
int T;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld%lld",&x,&a,&b);
		ans=0;
		while(true){
			long long r1,r2;
			r1=(x+a)/2;
			r1=x-r1;
			r2=sqrt(x+b);
			r2=x-r2;
			if(r1<=0&&r2<=0){
				break;
			}
			else if(r1>=r2){
				ans++;
				x-=r1;
			}
			else{
				ans++;
				x-=r2;
			}
		}
		ans+=x;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
