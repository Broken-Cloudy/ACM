#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,k,r,p;
signed main(){
	//freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		printf("? %lld %lld\n",1LL,1LL);
		fflush(stdout);
		scanf("%lld",&k);
		printf("? %lld %lld\n",n,m);
		fflush(stdout);
		scanf("%lld",&p);
		if(k==0){
			printf("! %lld %lld\n",1LL,1LL);
			fflush(stdout);
		}
		else if(k+p==m+n-2LL){//ÖØµþ 
			if(k<=m-1){
				printf("? %lld %lld\n",1LL,k+1);
				fflush(stdout);r=k+1;
				scanf("%lld",&k);
				printf("! %lld %lld\n",1LL+k/2,r-k/2);
				fflush(stdout);
			}
			else{
				printf("? %lld %lld\n",k-m+2LL,m);
				fflush(stdout);r=k-m+2LL;
				scanf("%lld",&k);
				printf("! %lld %lld\n",r+k/2,m-k/2);
				fflush(stdout);
			}
		}
		else if(((m+n-2LL)-(k+p))%2==1){
			if(k<=m-1){
				printf("? %lld %lld\n",1LL,k+1);
				fflush(stdout);r=k+1;
				scanf("%lld",&k);
				if(k%2==0){
					printf("! %lld %lld\n",1LL+k/2,r-k/2);
					fflush(stdout);
				}
				else{
					printf("! %lld %lld\n",1LL+(k+1)/2,r-k/2);
					fflush(stdout);
				}
			}
			else{
				printf("? %lld %lld\n",k-m+2LL,m);
				fflush(stdout);r=k-m+2LL;
				scanf("%lld",&k);
				printf("! %lld %lld\n",r+k/2,m-k/2);
				fflush(stdout);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
