#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int N,k,x,y=-1,z,r;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>N;
	for(k=1;k<=10000000;k++){
		if(N%k==0){
			z=N/k;
			if(12*z<3LL*k*k){
				continue;
			}
			r=sqrtl(12*z-3LL*k*k);
			if(r*r==(12*z-3LL*k*k)){
				if((r-3LL*k)%6LL==0){
					y=(r-3LL*k)/6LL;
					x=y+k;
					if(x>0&&y>0){
						break;
					}
					else{
						x=0;y=-1;
					}
				}
			}
		}
	}
	if(y==-1)printf("-1\n");
	else printf("%llu %llu\n",x,y);
	fclose(stdin);fclose(stdout);
	return 0;
}
