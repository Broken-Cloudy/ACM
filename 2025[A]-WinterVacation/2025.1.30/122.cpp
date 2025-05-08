#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,M,A,B,i,j,k,ans1,ans2,MAX_N,MAX_M;
double a[100009],b[100009],ans[100009],aa,bb;
signed main(){
	freopen("122.in","r",stdin);freopen("122.out","w",stdout);
	cin>>N;for(i=1;i<=N;i++)scanf("%lld%lf",&A,&aa),a[A]=aa,MAX_N=max(MAX_N,A);
	cin>>M;for(i=1;i<=M;i++)scanf("%lld%lf",&B,&bb),b[B]=bb,MAX_M=max(MAX_M,B);
	N=MAX_N;M=MAX_M;
	for(i=N;i>=M;i--){
		ans[i-M]=a[i]/b[M];
		for(k=M;k>=0;k--){
			j=i+k-M;
			a[j]-=ans[i-M]*b[k];
		}
	}
	for(i=0;i<=N;i++){
		if(abs(ans[i])>=0.05)ans1++;
		if(abs(a[i])>=0.05)ans2++;
	}
	printf("%lld ",ans1);
	if(ans1>0)for(i=N;i>=0;i--){
		if(abs(ans[i])>=0.05){
			printf("%lld %.1lf",i,ans[i]);
			ans1--;
			if(ans1)putchar(' ');
			else putchar('\n');
		}
	}
	else printf("0 0.0\n");
	printf("%lld ",ans2);
	if(ans2>0)for(i=N;i>=0;i--){
		if(abs(a[i])>=0.05){
			printf("%lld %.1lf",i,a[i]);
			ans2--;
			if(ans2)putchar(' ');
			else putchar('\n');
		}
	}
	else printf("0 0.0\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
