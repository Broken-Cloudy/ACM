#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[6009],n,i,j,fir;
int k[6009],ans,f;
signed main(){
	freopen("I.in","r",stdin);freopen("I.out","w",stdout);
	cin>>n;
	for(i=1;i<=2*n;i++){
		scanf("%lld",&a[i]);
		k[a[i]]++;
	}
	for(fir=n;fir>=1;fir++){//优先消除 
		if(a[fir]>=2){
			f=0;//初始化
			//优先消除 
			for(i=1;i<=2*n;i++){
				if(a[i]==n){
					
				}
			}
		}
	}
	 
	fclose(stdin);fclose(stdout);
	return 0;
}
