#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,N,f[1000009],m,M,T;
bool ff;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		N=sqrt(n);ff=0;
		if(N*N==n){
			for(i=1;i<N;i++){
				m=n-i*i;
				M=sqrt(m);
				if(M*M==m){
					ff=1;
					break;
				}
			}
			if(ff==1){
				printf("1\n");
			}
			else{
				printf("%lld\n",n);
			}
		}
		else{
			printf("inf\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
