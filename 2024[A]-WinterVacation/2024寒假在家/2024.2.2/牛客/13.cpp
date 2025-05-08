#include<bits/stdc++.h>
using namespace std;
long long T,n,len,i,k1,k2,ans;
int main(){
	freopen("13.in","r",stdin);freopen("13.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		if(n%6==0){
			ans=n/6;
		}
		else{
			k1=n/6;
			k2=n/6;
			ans=k1+k2;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
