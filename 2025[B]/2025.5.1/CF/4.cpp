#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[59],b[59],i,j,x,y,p2[59],l,r;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	for(i=0;i<=59;i++)p2[i]=(1LL<<i);
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=k;i++){
			printf("? %lld\n",i);fflush(stdout);
			scanf("%lld",&a[i]);
		}
		for(i=k;i>=1;i--){
			j=n+i-k;
			printf("? %lld\n",j);fflush(stdout);
			scanf("%lld",&b[i]);
		}
		x=0;
		for(i=1;i<=k;i++){
			if(a[i]!=b[i]){
				x=i;
				break;
			}
		}
		if(n==2*k){
			printf("! %lld %lld\n",k,k);fflush(stdout);
			continue;
		}
		else if(x==0&&n%k==0){
			printf("! -1\n");fflush(stdout);
		}
		else if(x==0){
			x=1;l=x;r=n-k;
			while(true){
				i=0;
				while(true){
					if(l+p2[i]*k<=r){
						j=l+p2[i]*k;
						printf("? %lld\n",j);fflush(stdout);
						scanf("%lld",&y);
						if(y!=a[1]){//y!=a[x]
							l=l+p2[i]*k;
							break;
						}
						else i++;
					}
					else{
						i--;
						break;
					}
				}
				if(i==0){
					break;
				}
			}
			for(i=l,j=1;i<=min(l+2*k,n);i++,j++){
				printf("? %lld\n",i);fflush(stdout);
				scanf("%lld",&y);
				if(y!=a[((j-1)%k+1)]){
					printf("! %lld %lld\n",i-1,n-i+1);fflush(stdout);
					break;
				}
			}
		}
		else{
			l=x;r=n-k;
			while(true){
				i=0;
				while(true){
					if(l+p2[i]*k<=r){
						j=l+p2[i]*k;
						printf("? %lld\n",j);fflush(stdout);
						scanf("%lld",&y);
						if(y!=a[x]){//y!=a[x]
							l=l+p2[i]*k;
							break;
						}
						else i++;
					}
					else{
						i--;
						break;
					}
				}
				if(i==0){
					break;
				}
			}
			for(i=l,j=x;i<=min(l+2*k,n);i++,j++){
				printf("? %lld\n",i);fflush(stdout);
				scanf("%lld",&y);
				if(y!=a[((j-1)%k+1)]){
					printf("! %lld %lld\n",i-1,n-i+1);fflush(stdout);
					break;
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
