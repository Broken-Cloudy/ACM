#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[59],b[59],i,j,x,y,p2[59],l,r,lastl,lasti,s;
bool FF;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(i=0;i<=30;i++)p2[i]=(1LL<<i);
	while(T--){
		scanf("%lld%lld",&n,&k);FF=0;
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
			continue;
		}
		else if(x==0){
			x=1;l=x;r=n-k;
			i=0;lasti=lastl=0;
			while(lasti!=i||lastl!=l){
				lasti=i;lastl=l;
				if(l+p2[i]*k<=r){
					if(i>=0)j=l+p2[i]*k;else j=l;
					printf("? %lld\n",j);fflush(stdout);
					scanf("%lld",&y);
					if(y!=a[1]){//y!=a[x]
						i--;
						if(i>=0)j=l+p2[i]*k;else j=l;
						l=j;
						i=0;
					}
					else i++;
				}
				else{
					i--;
					if(i>=0)j=l+p2[i]*k;else j=l;
					l=j;
					i=0;
					break;
				}
			}
			for(i=l,j=1;i<=min(l+2*k,n);i++,j++){
				printf("? %lld\n",i);fflush(stdout);
				scanf("%lld",&y);
				if(y!=a[((j-1)%k+1)]){
					for(s=k;s>=1;s--)if(y==b[s])break;
					if(i>r+1)printf("! %lld %lld\n",n-k,k);
					else if(i==k+1)printf("! %lld %lld\n",k,n-k);
					else if(b[(s-2+k)%k+1]==a[((j-2+k)%k+1)])printf("! -1\n");
					else if(i>r)printf("! %lld %lld\n",n-k,k);
					else printf("! %lld %lld\n",i-1,n-i+1);
					fflush(stdout);FF=1;
					break;
				}
			}
			if(FF==0){printf("! -1\n");fflush(stdout);}
		}
		else{
			l=x;r=n-k;
			i=0;lasti=lastl=0;
			while(lasti!=i||lastl!=l){
				lasti=i;lastl=l;
				if(l+p2[i]*k<=r){
					if(i>=0)j=l+p2[i]*k;else j=l;
					printf("? %lld\n",j);fflush(stdout);
					scanf("%lld",&y);
					if(y!=a[x]){//y!=a[x]
						i--;
						if(i>=0)j=l+p2[i]*k;else j=l;
						l=j;
						i=0;
					}
					else i++;
				}
				else{
					i--;
					if(i>=0)j=l+p2[i]*k;else j=l;
					l=j;
					i=0;
				}
			}
			for(i=l,j=x;i<=min(l+2*k,n);i++,j++){
				printf("? %lld\n",i);fflush(stdout);
				scanf("%lld",&y);
				if(y!=a[((j-1)%k+1)]){
					for(s=k;s>=1;s--)if(y==b[s])break;
					if(i>r+1)printf("! %lld %lld\n",n-k,k);
					else if(i==k+1)printf("! %lld %lld\n",k,n-k);
					else if(b[(s-2+k)%k+1]==a[((j-2+k)%k+1)])printf("! -1\n");
					else if(i>r)printf("! %lld %lld\n",n-k,k);
					else printf("! %lld %lld\n",i-1,n-i+1);
					fflush(stdout);FF=1;
					break;
				}
			}
			if(FF==0){printf("! -1\n");fflush(stdout);}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
