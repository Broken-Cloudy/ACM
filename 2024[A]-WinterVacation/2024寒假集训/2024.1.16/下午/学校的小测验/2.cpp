#include<iostream>
#include<cstdio>
using namespace std;
long long n,i,a[1000009],b[1000009];
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	for(i=1;i<=n;i++){
		printf("%lld",b[i]*i-b[i-1]*(i-1));
		if(i<n)putchar(' ');
		else putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
