#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,T,ans,i;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld%lld",&a,&b,&c);
		for(i=1;i<=5;i++){
			if(a>=c&&b>=c){
				c++;
			}
			else if(a>=b&&c>=b){
				b++;
			}
			else{
				a++;
			}
		}
		printf("%lld\n",a*b*c);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
