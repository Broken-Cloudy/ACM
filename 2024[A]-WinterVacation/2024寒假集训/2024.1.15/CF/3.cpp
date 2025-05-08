#include<bits/stdc++.h>
using namespace std;
long long T,n,f,a,b,i,mess[200009];
int main(){
	//freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld%lld%lld",&n,&f,&a,&b);
		for(i=1;i<=n;i++){
			scanf("%lld",&mess[i]);
		}
		for(i=1;i<=n;i++){
			if((mess[i]-mess[i-1])*a<=b){
				f-=(mess[i]-mess[i-1])*a;
			}
			else{
				f-=b;
			}
		}
		if(f>0){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
