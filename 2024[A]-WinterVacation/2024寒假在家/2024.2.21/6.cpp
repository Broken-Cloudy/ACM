#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100009],i,T,num,ci;
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n%2==0){
			printf("YES\n");
		}
		else{
			for(i=2;i<=n;i++){
				if(a[i]<a[i-1]){
					if(i%2==0){
						ci=a[i-1]-a[i];
						a[i-1]+=ci*(i-1);
						a[i]+=ci*i;
						num=max(num,ci*(i-1));
						num=max(num,ci*(i));
					}
					else{
						
					}
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
