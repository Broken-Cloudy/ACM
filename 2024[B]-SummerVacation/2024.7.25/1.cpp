#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,sumnum,maxsum,sum,i,j;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		sumnum=maxsum=sum=0;
		for(i=2;i<=n;i++){
			sum=0;
			for(j=1;i*j<=n;j++){
				sum+=i*j;
			}
			if(sum>maxsum){
				maxsum=sum;
				sumnum=i;
			}
		}
		printf("%lld\n",sumnum);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
