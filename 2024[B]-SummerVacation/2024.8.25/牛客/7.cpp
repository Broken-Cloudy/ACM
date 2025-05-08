#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,i,a[200009];
signed main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>n>>k;
	if(n==1){
		if(k==2){
			printf("1 1\n");
		}
		else printf("-1\n");
	}
	else if(n==2){
		if(k==3){
			printf("1 2 1 2\n");
		}
		else if(k==2){
			printf("1 2 2 1\n");
		}
		else if(k==1){
			printf("1 1 2 2\n");
		}
		else printf("-1\n");
	}
	else{
		if(k==0){
			for(i=1;i<=n;i++){
				if(i==n)printf("%lld %lld\n",i,i);
				else printf("%lld %lld ",i,i);
			}
		}
		else if(k==1){
			a[1]=1;a[n+2]=n;
			for(i=2;i<=1+n;i++)a[i]=i-1;
			for(i=n+3;i<=2*n;i++)a[i]=i-n-1;
			for(i=1;i<=2*n;i++){
				if(i==2*n)printf("%lld\n",a[i]);
				else printf("%lld ",a[i]);
			}
		}
		else{
			for(i=1;i<=n;i++)a[i]=i,a[i+n]=i;
			swap(a[2*n],a[2*n-(n+1-k)]);
			for(i=1;i<=2*n;i++){
				if(i==2*n)printf("%lld\n",a[i]);
				else printf("%lld ",a[i]);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
