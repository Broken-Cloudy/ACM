#include<iostream>
#include<cstdio>
using namespace std;
long long n,i,f[5009],ans;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;f[1]=1;
	for(i=1;i<=n;i++){
		f[i]=f[i-1]+i;
	}
	for(i=1;i<=n;i++){
		ans+=f[i];
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
