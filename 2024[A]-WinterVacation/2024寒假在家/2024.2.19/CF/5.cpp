#include<iostream>
using namespace std;
long long T,i,n,k,deep,pow[65],ans;
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;pow[1]=2;pow[0]=1;
	for(i=2;i<=36;i++)pow[i]=pow[i-1]*2;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&n,&k);deep=1;
		while(true){
			int r=((n+pow[deep-1])/pow[deep]);
			if(k<=r){
				break;
			}
			else{
				k-=r;
			}
			deep++;
		}
		ans=pow[deep]*k-pow[deep]/2;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
