#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,f[100009],s,i,j;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;f[0]=1;
	for(s=1;s<n;s++){
		for(j=0;j<=n/2;j++)printf("%lld ",f[j]);
		for(i=n;i>=s+1;i-=2){
			j=i/2;
			f[j]+=f[j-1];
		}
		putchar('\n');
	}
	for(j=0;j<=n/2;j++)printf("%lld ",f[j]);putchar('\n');
	printf("%lld\n",f[n/2]);
	fclose(stdin);fclose(stdout);
	return 0;
}
